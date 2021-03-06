#include "reader.h"
#include "latypes.h"
#include "tokenizer.h"
#include "core.h"

#include <iostream>


std::string prompt(const std::string &prompt_string,
			std::istream& in_stream, 
				std::ostream& out_stream)
{
	std::string res;
	
	out_stream << prompt_string;
	
	std::getline(in_stream,res);
	if(in_stream.bad())
		return "prompt: stream error!";
	
	return res;

}


laValPtr read_form(Tokenizer &tok)
{
	if(tok.state != Tokenizer_State::START)
		//TODO:error
		return la_nil();

	tok.next();

	switch(tok.state)
	{
		case Tokenizer_State::L_PARAN:
			return read_list(tok);
		case Tokenizer_State::NUMBER:
		case Tokenizer_State::STRING:
		case Tokenizer_State::SYMBOL:
			return read_atom(tok);	
		default:
			//TODO:error
			return la_nil();
	}
}

laValPtr read_list(Tokenizer &tok)
{
	if(tok.state != Tokenizer_State::L_PARAN)
		//TODO:error
		return la_nil();
	
	laList 	    *res  = new laList();
	std::string token = tok.next();
	
	while(tok.state != Tokenizer_State::R_PARAN)
	{

		if(tok.state == Tokenizer_State::END)
			//TODO:error
			return la_nil();
		
		if(tok.state == Tokenizer_State::L_PARAN)//list in list
			(*res).insert(read_list(tok));
		else if(!(tok.state == Tokenizer_State::WHITESPACE))
			(*res).insert(read_atom(tok));
	
		token = tok.next();		 
	}
		
	return laValPtr(res);
}

laValPtr read_atom(Tokenizer &tok)
{

	switch(tok.state)
	{
		case Tokenizer_State::END:
			//TODO:error
			return la_nil(); 
		case Tokenizer_State::NUMBER:
			return la_number(tok.curr());
		case Tokenizer_State::STRING:
			return la_string(tok.curr());
		default://TODO:Symbol
			return la_symbol(tok.curr());

	}

}
