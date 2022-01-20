#include "core.h"
#include "latypes.h"



#include <memory>

laValPtr la_sum(laListPtr args,laEnv &env)
{
	laValPtr curr;
	double	 res=0;

	if(args->size() == 0)
		//TODO:error
		return laValPtr(new laNil);

	for(int i=0;i<args->size();i++)
	{
		curr = args->at(i);
		if(curr->get_type() != laType::Number)
			return laValPtr(new laNil());
			//TODO:error
		res+= (std::dynamic_pointer_cast
				<laNumber>(curr))->value();
	}

	return laValPtr(new laNumber(res)); 

}

laValPtr la_difference(laListPtr args,laEnv &env)
{
	laValPtr curr;

	if(args->size() == 0)
		//TODO:error
		return laValPtr(new laNil);

	//res = first argument
	if((args->at(0))->get_type() != laType::Number)
		//TODO: error
		return laValPtr(new laNil());		

	double res = (std::dynamic_pointer_cast
				<laNumber>(args->at(0)))->value();


	//if number of args is 1, return -arg
	if(args->size() == 1)
		return laValPtr(new laNumber(0-res));



	for(int i=1;i<args->size();i++)
	{
		curr = args->at(i);
		if(curr->get_type() != laType::Number)
			continue;
			//TODO:error
		res-= (std::dynamic_pointer_cast
				<laNumber>(curr))->value();
	}

	return laValPtr(new laNumber(res)); 

}

laValPtr la_product(laListPtr args,laEnv &env)
{
	laValPtr curr;
	double	 res=1;
	
	if(args->size() == 0)
		//TODO:error
		return laValPtr(new laNil());

	for(int i=0;i<args->size();i++)
	{
		curr = args->at(i);
		if(curr->get_type() != laType::Number)
			return laValPtr(new laNil());
			//TODO:error
		res*= (std::dynamic_pointer_cast
				<laNumber>(curr))->value();
	}

	return laValPtr(new laNumber(res)); 


}

laValPtr la_quotient(laListPtr args,laEnv &env)
{
	laValPtr curr;

	if(args->size() == 0)
		//TODO:error
		return laValPtr(new laNil);

	//res = first argument
	if((args->at(0))->get_type() != laType::Number)
		//TODO: error
		return laValPtr(new laNil());		

	double res = (std::dynamic_pointer_cast
				<laNumber>(args->at(0)))->value();


	for(int i=1;i<args->size();i++)
	{
		curr = args->at(i);
		if(curr->get_type() != laType::Number)
			continue;
			//TODO:error
		res/= (std::dynamic_pointer_cast
				<laNumber>(curr))->value();
	}

	return laValPtr(new laNumber(res)); 

}
