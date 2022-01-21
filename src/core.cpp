#include "core.h"
#include "latypes.h"
#include "eval.h"


#include <memory>
#include <string>


laValPtr la_nil()
{
	return laValPtr(laNilVal());
}

laValPtr la_list()
{
	return laValPtr(new laList());
}
laValPtr la_number(const int val)
{
	return laValPtr(new laNumber(val));
}

laValPtr la_number(const std::string val)
{
	return laValPtr(new laNumber(val));
}


laValPtr la_string(const std::string val)
{
	return laValPtr(new laString(val));
}
laValPtr la_symbol(const std::string val)
{
	return laValPtr(new laSymbol(val));
}




laValPtr la_sum(laListPtr args,laEnv &env)
{
	laValPtr curr;
	double	 res=0;

	if(args->size() == 0)
		//TODO:error
		return la_nil();

	for(int i=0;i<args->size();i++)
	{
		curr = args->at(i);
		if(curr->get_type() != laType::Number)
			return la_nil();
			//TODO:error
		res+= (std::dynamic_pointer_cast
				<laNumber>(curr))->value();
	}

	return la_number(res); 

}

laValPtr la_difference(laListPtr args,laEnv &env)
{
	laValPtr curr;

	if(args->size() == 0)
		//TODO:error
		return la_nil();

	//res = first argument
	if((args->at(0))->get_type() != laType::Number)
		//TODO: error
		return la_nil();		

	double res = (std::dynamic_pointer_cast
				<laNumber>(args->at(0)))->value();


	//if number of args is 1, return -arg
	if(args->size() == 1)
		return la_number(0-res);




	for(int i=1;i<args->size();i++)
	{
		curr = args->at(i);
		if(curr->get_type() != laType::Number)
			return la_nil();
			//TODO:error
		res-= (std::dynamic_pointer_cast
				<laNumber>(curr))->value();
	}

	return la_number(res); 

}

laValPtr la_product(laListPtr args,laEnv &env)
{
	laValPtr curr;
	double	 res=1;
	
	if(args->size() == 0)
		//TODO:error
		return la_nil();

	for(int i=0;i<args->size();i++)
	{
		curr = args->at(i);
		if(curr->get_type() != laType::Number)
			return la_nil();
			//TODO:error
		res*= (std::dynamic_pointer_cast
				<laNumber>(curr))->value();
	}

	return la_number(res); 


}

laValPtr la_quotient(laListPtr args,laEnv &env)
{
	laValPtr curr;

	if(args->size() == 0)
		//TODO:error
		return la_nil(); 

	//res = first argument
	if((args->at(0))->get_type() != laType::Number)
		//TODO: error
		return la_nil(); 

	double res = (std::dynamic_pointer_cast
				<laNumber>(args->at(0)))->value();


	for(int i=1;i<args->size();i++)
	{
		curr = args->at(i);
		if(curr->get_type() != laType::Number)
			return la_nil();
			//TODO:error
		res/= (std::dynamic_pointer_cast
				<laNumber>(curr))->value();
	}

	return la_number(res); 

}

laValPtr la_truth_value(laListPtr args,laEnv &env)
{
	if(args->size() != 1)
		//TODO:error
		return la_nil();

	if((args->at(0))->is_true())
		return la_number(1); 
	else
		return la_nil();


}


laValPtr la_equals(laListPtr args,laEnv& env)
{
	if(args->size() == 0)
		//TODO:error
		return la_nil(); 


	laValPtr first = args->at(0);
	laValPtr curr;

	
	for(int i=0;i<args->size();i++)
	{
		curr = args->at(i);
		if(first->get_type() != curr->get_type())
			//TODO:error
			return la_nil();	
		
		if(!first->equals(curr))
			return la_nil();

	}
	return la_number(1);

}


laValPtr la_if(laListPtr args,laEnv &env)
{
	if(args->size() != 4)//if cond then else
		//TODO:error
		return la_nil(); 

	laValPtr cond = eval_sex(args->at(1),env);
	

	if(cond->is_true())
		return eval_sex(args->at(2),env);
	else
		return eval_sex(args->at(3),env);

}
