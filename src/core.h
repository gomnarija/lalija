#ifndef CORE_H
#define CORE_H

#include "latypes.h"


laValPtr	la_sum(laListPtr args,laEnv& env);
laValPtr	la_difference(laListPtr args,laEnv& env);
laValPtr	la_product(laListPtr args,laEnv& env);
laValPtr	la_quotient(laListPtr args,laEnv& env);




#endif
