#include "eval.h"
#include "latypes.h"




laValPtr eval_list(laValPtr ,laEnv &);
laValPtr eval_atom(laValPtr ,laEnv &);



laValPtr env_search(laValPtr symbol, laEnv &env)
{
	laEnv *curr = &env;
	while(curr != nullptr)
	{
		laValPtr res = curr->get_val(symbol->print());
		if(res->get_type() == laType::Nil)
			curr = curr->get_upper_env();		
		else
			return res;
	}

	//TODO:error
	return laValPtr(new laNil());
}



laValPtr eval_sex(laValPtr ast,laEnv &env)
{
	switch(ast->get_type())
	{
		case laType::Number:
		case laType::String:
		case laType::Symbol:
			return eval_atom(ast,env);
		case laType::List:
			return eval_list(ast,env);
		default:
			return laValPtr(new laNil());
	}

}
laValPtr eval_list(laValPtr list,laEnv &env)
{
	laValPtr  curr;
	laListPtr  res(new laList());
	laListPtr list_ptr = std::dynamic_pointer_cast<laList>(list);
	for(int i=0;i<list_ptr->size();i++)
	{
		curr = list_ptr->at(i);
		if(curr->get_type() == laType::List)
			res->insert(eval_list(curr,env));
		else
			res->insert(eval_atom(curr,env));
	}
	return res;
}

laValPtr eval_atom(laValPtr atom,laEnv &env)
{
	switch(atom->get_type())
	{
		//self-eval
		case laType::Number:
		case laType::String:
			return atom;
		case laType::Symbol:
			return env_search(atom,env);
		default:
			return laValPtr(new laNil());
	}
}
