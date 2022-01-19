#include "tokenizer.h"


bool Tokenizer::is_end()
{
	if(this->state == Tokenizer_State::END)
		return true;


	bool res = this->next_it>=this->input_string.end();

	if(res)
		this->state = Tokenizer_State::END;		

	return res;

}

std::string Tokenizer::curr()
{

	if(this->state == Tokenizer_State::START)
		return this->next();

	return std::string(this->curr_it,
			this->next_it);


}

std::string Tokenizer::next()
{

	if(this->state == Tokenizer_State::END)
	{
		//TODO:warn
		return "";
	}

	this->curr_it = this->next_it;	

	if(tokenize())
	{
		//TODO:error handling
		return "";
	}


	return std::string(this->curr_it,
			this->next_it);


}

int Tokenizer::tokenize()
{
	//0  - success
	//-1 - end
	//-2 - error

	std::string::iterator it=this->curr_it;

	//check if next_it is at end
	if(is_end())
		return -1;

	
	get_state();

	do
	{
		it++;
		if(it > this->input_string.end())
		{
			//TODO:error
			this->state = Tokenizer_State::END;
			return -2;
		}			

	}while(!is_token_end(it));

	
	this->next_it = it;
	
	return 0;
}

void Tokenizer::get_state()
{
	char c = *(this->curr_it);

	
	switch(c)	
	{
		case '(':
			this->state = Tokenizer_State::L_PARAN;
				break;
		case ')':
			this->state = Tokenizer_State::R_PARAN;
				break;
		case ' ':
			this->state = Tokenizer_State::WHITESPACE;
				break;
		case '"':
			this->state = Tokenizer_State::STRING;
				break;
		default:
			if(c>='0' && c<='9')
				this->state = 
					Tokenizer_State::NUMBER; 
			else
				this->state = 
					Tokenizer_State::SYMBOL;
	}

}

bool Tokenizer::is_token_end(std::string::iterator &it)
{

	char c = *(it);

	//parentheses, always length of one
	if(this->state == Tokenizer_State::L_PARAN ||
		this->state == Tokenizer_State::R_PARAN)
			return true;

	//whitespace, parse until first non-whitespace character
	if(this->state == Tokenizer_State::WHITESPACE &&
		c != ' ')
			return true;

	//string, parse until ", 
	//	then increment it to the next character
	if(this->state == Tokenizer_State::STRING &&
		c == '"')
	{
			it++;
			return true;
	}
	//number, parse until first non-digit
	if(this->state == Tokenizer_State::NUMBER &&
		(c < '0' || c > '9') && c != '.')
			return true;
	
	//atomic symbol, parse until whitespace,parentheses or stream end
	if(this->state == Tokenizer_State::SYMBOL &&
		(c==' ' || c=='(' || c==')' || 
			it == this->input_string.end()))
				return true;

	return false;
}
