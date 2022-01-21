#ifndef CORE_H
#define CORE_H


#include "latypes.h"


#include <string>

laValPtr	la_sum(laListPtr args,laEnv& env);
laValPtr	la_difference(laListPtr args,laEnv& env);
laValPtr	la_product(laListPtr args,laEnv& env);
laValPtr	la_quotient(laListPtr args,laEnv& env);

laValPtr	la_truth_value(laListPtr args,laEnv& env);
laValPtr	la_equals(laListPtr args,laEnv& env);
laValPtr	la_if(laListPtr args,laEnv& env);


laValPtr	la_nil();
laValPtr	la_list();
laValPtr	la_number(const int = 0);
laValPtr	la_number(const std::string);
laValPtr	la_symbol(const std::string);
laValPtr	la_string(const std::string = "str");


#endif
