#include "reader.h"

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
