#ifndef READER_H
#define READER_H

#include "latypes.h"
#include "tokenizer.h"

#include <string>


std::string prompt(const std::string &,std::istream&,std::ostream&);



laValPtr read_atom(Tokenizer &tok);
laValPtr read_list(Tokenizer &tok);
laValPtr read_form(Tokenizer &tok);

#endif
