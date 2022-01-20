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


std::string laSymbol::print()
{
	return this->m_value;
}

std::string laNil::print()
{
	return "laNil";
}


laValPtr laEnv::get_val(std::string key)
{
	if(this->m_map.find(key) != this->m_map.end())
		return this->m_map.at(key);	
	else
		//TODO:error
		return laValPtr(new laNil);

}

void laEnv::set_val(std::string key,laValPtr val)
{
	//sets only if key already exists in map

	if(this->m_map.find(key) != this->m_map.end())
		this->m_map.at(key) = val;
	//TODO:error
}

void laEnv::insert_val(std::string key,laValPtr val)
{
	//inserts new key:val pair in map


	if(this->m_map.find(key) == this->m_map.end())
		this->m_map[key] = laValPtr(val);
	//TODO:error

}

void laEnv::fset_val(std::string key,laValPtr val)
{
	this->m_map[key] = val;
}
