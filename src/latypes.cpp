#include "latypes.h"


#include <string>
#include <stdexcept>
#include <float.h>
#include <vector>
#include <sstream>


std::string laVal::print()
{
	return "laVal";
}

laNumber::laNumber(std::string value)
{
	try{
		m_value = std::stod(value);
		}
	catch(const std::invalid_argument &ia)
	{
		//TODO:error
		m_value = 0;
	}
	catch(const std::out_of_range &oor)
	{
		//TODO:error
		m_value = DBL_MAX;
	}	

}

std::string laNumber::print()
{
	std::ostringstream ss;
	ss << this->m_value;

	return ss.str();
}


std::string laString::print()
{
	return this->m_value;
}


laList::laList(std::vector<laValPtr> list)
{
	for(auto val : list)
		this->m_items.push_back(val);
}

void laList::insert(laValPtr val)
{
	this->m_items.push_back(val);
}

laValPtr laList::at(const int n)
{
	return this->m_items[n];
}

std::string laList::print()
{
	std::string res("(");
	
	for(int i=0;i<this->size();i++)
	{
		res += (this->m_items[i])->print();	
		if(i<this->size()-1)
			res += " ";
	}

	res+= ")";
	return res;
}


std::string laNil::print()
{
	return "laNil";
}
