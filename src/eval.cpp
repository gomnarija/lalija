#include "eval.h"
#include "latypes.h"
#include "core.h"

#include <map>

laValPtr eval_list(laValPtr ,laEnv &);
laValPtr eval_atom(laValPtr ,laEnv &);




std::map<std::string,
	laValPtr (*)(laListPtr, laEnv&)> operators=
	{
		{"+",&la_sum},
		{"-",&la_difference},	
		{"*",&la_product},	
		{"/",&la_quotient},
		{"?",&la_truth_value},
		{"!",&la_not_truth_value},
		{"=",&la_equals},
		{">",&la_more},
		{"<",&la_less},
		{">=",&la_more_or_equal},
		{"<=",&la_less_or_equal},
		{"==",&la_real_equals},
		{"&",&la_and},
		{"|",&la_or}
	};


std::map<std::string,
	laValPtr (*)(laListPtr, laEnv&)> ne_operators=
	{	
		{"if",&la_if}
	};


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
	return la_nil();
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
			return la_nil(); 
	}

}
laValPtr eval_list(laValPtr list,laEnv &env)
{
	laListPtr  args(new laList());
	laListPtr  list_ptr = std::dynamic_pointer_cast<laList>(list);
	laValPtr   curr;
	laValPtr   op;

	if(list_ptr->size() == 0)
		return la_list();

	//operation
	op = list_ptr->at(0);

	if(op->get_type() != laType::Symbol)
		//TODO:error
		return la_nil();


	//no eval
	if(ne_operators.find(op->print()) != ne_operators.end())
		return ne_operators.at(op->print())
			(std::dynamic_pointer_cast<laList>(list),env);

	//eval args and add them to args list
	for(int i=1;i<list_ptr->size();i++)
	{
		curr = list_ptr->at(i);
		if(curr->get_type() == laType::List)
			args->insert(eval_list(curr,env));
		else
			args->insert(eval_atom(curr,env));
	}

	//operator
	if(operators.find(op->print()) !=operators.end())
		return operators.at(op->print())(args,env);
	else//TODO:functions
		return la_nil(); 
		
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
			return la_nil();
	}
}
