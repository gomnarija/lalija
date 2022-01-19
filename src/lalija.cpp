#include "reader.h"
#include "tokenizer.h"
#include "latypes.h"

#include <iostream>


laValPtr 	READ(std::string& input);
laValPtr 	EVAL(laValPtr ast);
std::string	PRINT(laValPtr ast);

std::string rep();

int main()
{

	while("lalija")
		std::cout  << rep() << "\n";
	
	return 0;	
}

std::string rep()
{
	std::string input = prompt("laza>",std::cin,std::cout);
	
	return PRINT(EVAL(READ(input)));
}

laValPtr READ(std::string& input)
{	
	Tokenizer tok(input);
	return read_form(tok);	

}

laValPtr EVAL(laValPtr ast)
{
	return ast;
}

std::string PRINT(laValPtr ast)
{
	return ast->print();
}

