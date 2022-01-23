#include "core.h"
#include "latypes.h"
#include "eval.h"


#include <memory>
#include <string>



extern std::string lalija;


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

laValPtr la_not_truth_value(laListPtr args,laEnv &env)
{
	if(args->size() != 1)
		//TODO:error
		return la_nil();

	if(!((args->at(0))->is_true()))
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

laValPtr la_more(laListPtr args,laEnv& env)
{
	if(args->size() == 0)
		//TODO:error
		return la_nil(); 

	
	//ref = first argument
	if((args->at(0))->get_type() != laType::Number)
		//TODO: error
		return la_nil(); 

	double ref = (std::dynamic_pointer_cast
				<laNumber>(args->at(0)))->value();

	laValPtr curr;
	
	for(int i=1;i<args->size();i++)
	{
		curr = args->at(i);
		if(curr->get_type() != laType::Number)
			//TODO:error
			return la_nil();	
		
		if((std::dynamic_pointer_cast<laNumber>(curr))->value()
			>= ref)
			return la_nil();

	}
	return la_number(1);

}

laValPtr la_less(laListPtr args,laEnv& env)
{
	if(args->size() == 0)
		//TODO:error
		return la_nil(); 

	
	//ref = first argument
	if((args->at(0))->get_type() != laType::Number)
		//TODO: error
		return la_nil(); 

	double ref = (std::dynamic_pointer_cast
				<laNumber>(args->at(0)))->value();

	laValPtr curr;
	
	for(int i=1;i<args->size();i++)
	{
		curr = args->at(i);
		if(curr->get_type() != laType::Number)
			//TODO:error
			return la_nil();	
		
		if((std::dynamic_pointer_cast<laNumber>(curr))->value()
			<= ref)
			return la_nil();

	}
	return la_number(1);

}

laValPtr la_more_or_equal(laListPtr args,laEnv& env)
{
	if(args->size() == 0)
		//TODO:error
		return la_nil(); 

	
	//ref = first argument
	if((args->at(0))->get_type() != laType::Number)
		//TODO: error
		return la_nil(); 

	double ref = (std::dynamic_pointer_cast
				<laNumber>(args->at(0)))->value();

	laValPtr curr;
	
	for(int i=1;i<args->size();i++)
	{
		curr = args->at(i);
		if(curr->get_type() != laType::Number)
			//TODO:error
			return la_nil();	
		
		if((std::dynamic_pointer_cast<laNumber>(curr))->value()
			> ref)
			return la_nil();

	}
	return la_number(1);

}

laValPtr la_less_or_equal(laListPtr args,laEnv& env)
{
	if(args->size() == 0)
		//TODO:error
		return la_nil(); 

	
	//ref = first argument
	if((args->at(0))->get_type() != laType::Number)
		//TODO: error
		return la_nil(); 

	double ref = (std::dynamic_pointer_cast
				<laNumber>(args->at(0)))->value();

	laValPtr curr;
	
	for(int i=1;i<args->size();i++)
	{
		curr = args->at(i);
		if(curr->get_type() != laType::Number)
			//TODO:error
			return la_nil();	
		
		if((std::dynamic_pointer_cast<laNumber>(curr))->value()
			< ref)
			return la_nil();

	}
	return la_number(1);

}

laValPtr la_real_equals(laListPtr args,laEnv& env)
{
	if(args->size() == 0)
		//TODO:error
		return la_nil(); 


	laValPtr first = args->at(0);
	laValPtr curr;

	
	for(int i=0;i<args->size();i++)
	{
		curr = args->at(i);
		if(first != curr)
			return la_nil();	
		
	}
	return la_number(1);

}

laValPtr la_and(laListPtr args,laEnv& env)
{
	if(args->size() == 0)
		//TODO:error
		return la_nil(); 


	laValPtr curr;

	
	for(int i=0;i<args->size();i++)
	{
		curr = args->at(i);
		
		if(!(curr->is_true()))
			return la_nil();

	}
	return la_number(1);

}

laValPtr la_or(laListPtr args,laEnv& env)
{
	if(args->size() == 0)
		//TODO:error
		return la_nil(); 


	laValPtr curr;

	
	for(int i=0;i<args->size();i++)
	{
		curr = args->at(i);
		
		if((curr->is_true()))
			return la_number(1);

	}
	return la_nil();

}


//no eval
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


//no eval
laValPtr la_set(laListPtr args,laEnv &env)
{	
	if(args->size() != 3)//set symbol value
		//TODO:error
		return la_nil();


	if((args->at(1))->get_type() != laType::Symbol)
		//TODO:error
		return la_nil();


	//TODO:error if eval_sex returns nil
	env.set_val((args->at(1))->print(),eval_sex(args->at(2),env));

	return args->at(1);


}

//no eval
laValPtr la_fset(laListPtr args,laEnv &env)
{	
	if(args->size() != 3)//fset symbol value
		//TODO:error
		return la_nil();


	if((args->at(1))->get_type() != laType::Symbol)
		//TODO:error
		return la_nil();

	//TODO:error if eval_sex returns nil
	env.fset_val((args->at(1))->print(),eval_sex(args->at(2),env));


	return args->at(1);

}

//no eval
laValPtr la_val(laListPtr args,laEnv &env)
{	
	if(args->size() != 3)//val symbol value
		//TODO:error
		return la_nil();


	if((args->at(1))->get_type() != laType::Symbol)
		//TODO:error
		return la_nil();


	//TODO:error if eval_sex returns nil
	env.insert_val((args->at(1))->print(),eval_sex(args->at(2),env));


	return args->at(1);
}


//no eval
laValPtr la_function(laListPtr args,laEnv& env)
{
	if(args->size() < 4)//function name args body body body...
		//TODO:error
		return la_nil();

	if((args->at(2))->get_type() != laType::List)
		//TODO:error
		return la_nil();

	laListPtr body(new laList());

	for(int i=3;i<args->size();i++)
		body->insert(args->at(i));

	laFunctionPtr fun = laFunctionPtr(new laFunction(
			(args->at(1))->print(),
			  std::dynamic_pointer_cast<laList>(args->at(2))
								   ,body));


	env.insert_val((args->at(1))->print(),
		std::dynamic_pointer_cast<laVal>(fun));
	
	return args->at(1);
}

//no eval
laValPtr la_let(laListPtr args,laEnv& env)
{
	if(args->size() < 3)//let var body body....
		//TODO:error
		return la_nil();

	if((args->at(1))->get_type() != laType::List)
		//TODO:error
		return la_nil();

	laListPtr vars = std::dynamic_pointer_cast<laList>(args->at(1));



	laEnv local_env(&env);

	for(int i=0;i<vars->size();i++)
	{
		if(vars->at(i)->get_type() != laType::List)
			return la_nil();//TODO:error
	
		laListPtr var = std::dynamic_pointer_cast<laList>(vars->at(i));
		local_env.insert_val(var->at(0)->print(),var->at(1));

	}
	
	laValPtr	res = la_nil();

	for(int i=2;i<args->size();i++)
	{
		res = eval_sex(args->at(i),local_env);
	}

	return res;
}


laValPtr la_quit(laListPtr args,laEnv& env)
{
	lalija = "ne_lalija";
	return la_string(":)");
}
