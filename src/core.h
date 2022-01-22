#ifndef CORE_H
#define CORE_H


#include "latypes.h"


#include <string>

laValPtr	la_sum(laListPtr args,laEnv& env);
laValPtr	la_difference(laListPtr args,laEnv& env);
laValPtr	la_product(laListPtr args,laEnv& env);
laValPtr	la_quotient(laListPtr args,laEnv& env);

laValPtr	la_truth_value(laListPtr args,laEnv& env);
laValPtr	la_not_truth_value(laListPtr args,laEnv& env);
laValPtr	la_equals(laListPtr args,laEnv& env);
laValPtr	la_more(laListPtr args,laEnv& env);
laValPtr	la_less(laListPtr args,laEnv& env);
laValPtr	la_more_or_equal(laListPtr args,laEnv& env);
laValPtr	la_less_or_equal(laListPtr args,laEnv& env);
laValPtr	la_real_equals(laListPtr args,laEnv& env);
laValPtr	la_and(laListPtr args,laEnv& env);
laValPtr	la_or(laListPtr args,laEnv& env);
laValPtr	la_if(laListPtr args,laEnv& env);


laValPtr	la_set(laListPtr args,laEnv& env);
laValPtr	la_fset(laListPtr args,laEnv& env);
laValPtr	la_val(laListPtr args,laEnv& env);



laValPtr	la_nil();
laValPtr	la_list();
laValPtr	la_number(const int = 0);
laValPtr	la_number(const std::string);
laValPtr	la_symbol(const std::string);
laValPtr	la_string(const std::string = "str");




#endif
