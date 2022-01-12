#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <string>

enum Tokenizer_State
		{
		START,
		WHITESPACE,
		SYMBOL,
		NUMBER,
		STRING,
		L_PARAN,
		R_PARAN,
		END};

struct Tokenizer
{
	Tokenizer(std::string &input_str)
		:input_string{input_str}
	{
		this->curr_it  = this->input_string.begin();
		this->next_it  = this->curr_it;
		
		if(this->curr_it == this->input_string.end())//empty stream
			this->state	= Tokenizer_State::END;
		else
			this->state     = Tokenizer_State::START;
	}
	

	Tokenizer_State 		state;
	
	std::string next();
	std::string curr();

	bool	    is_end();
	
private:
	std::string			&input_string;			
	std::string::iterator		curr_it,next_it;
	
	int tokenize();
	void get_state();
	bool is_token_end(std::string::iterator &);	

	
};

#endif
