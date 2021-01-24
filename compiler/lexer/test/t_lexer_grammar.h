#ifndef _T_LEXER_GRAMMAR_H_
#define _T_LEXER_GRAMMAR_H_

#include <string>
#include <memory>
#include "../includes/lexer_grammar.h"
#include "create_obj.h"


void t_tokenize_number(std::string&& );
void t_tokenize_string(std::string&& );
void t_tokenize_word(std::string&& );
void t_tokenize_char(std::string&& );
void t_tokenize_operator(std::string&& );

#endif // !_T_LEXER_GRAMMAR_H_;