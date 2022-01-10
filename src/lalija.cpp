#include "reader.h"


#include <iostream>







std::string READ(const std::string& input);
int EVAL();
int PRINT();

std::string rep(const std::string& input);

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



std::string rep(const std::string& input)
{
	return input;
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

