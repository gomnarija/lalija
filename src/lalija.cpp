#include "reader.h"
#include "tokenizer.h"

#include <iostream>







std::string READ(std::string& input);
int EVAL();
int PRINT();

std::string rep(std::string& input);

int main()
{
	std::string input;
	while("lalija")
	{
		input = prompt("laza>",std::cin,std::cout);
		std::cout << rep(input) << "\n";
	}
	return 0;	
}



std::string rep(std::string& input)
{
	Tokenizer t(input);
	while(!t.is_end())
	{
		auto res = t.next();
		if(t.state != Tokenizer_State::WHITESPACE)
			std::cout << res << "\n";
	}
	return "";
}


std::string READ()
{
	return "test";
}
int EVAL()
{
	return 0;
}
int PRINT()
{
	return 0;
}

