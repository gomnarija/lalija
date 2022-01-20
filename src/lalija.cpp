#include "reader.h"
#include "tokenizer.h"
#include "latypes.h"
#include "eval.h"

#include <iostream>


laValPtr 	READ(std::string& input);
laValPtr 	EVAL(laValPtr ast,laEnv &env);
std::string	PRINT(laValPtr ast);

std::string rep(laEnv &env);

int main()
{

	laEnv	global_env;
	global_env.insert_val("pi",laValPtr(new laNumber(3.141592653589793)));
	
	while("lalija")
		std::cout  << rep(global_env) << "\n";
	
	return 0;	
}

std::string rep(laEnv &env)
{
	std::string input = prompt("laza>",std::cin,std::cout);
	
	return PRINT(EVAL(READ(input),env));
}

laValPtr READ(std::string& input)
{	
	Tokenizer tok(input);
	return read_form(tok);	

}

laValPtr EVAL(laValPtr ast,laEnv &env)
{
	return eval_sex(ast,env);
}

std::string PRINT(laValPtr ast)
{
	return ast->print();
}

