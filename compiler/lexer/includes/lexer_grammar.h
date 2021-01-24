#ifndef _LEXER_GRAMMAR_H_
#define _LEXER_GRAMMAR_H_
#define DEBUG_INF

#include <iostream> // for size_t type;
#include <memory>
#include "token.h"

class lexer_grammar
{
public:
    virtual ~lexer_grammar(){};

    virtual token* tokenize_number() = 0;
    virtual token* tokenize_string() = 0;
    virtual token* tokenize_char() = 0;
    virtual token* tokenize_word() = 0;
    virtual token* tokenzie_operator() = 0;
    virtual void tokenize_comment() = 0;
    virtual char get(const size_t ) = 0;
    virtual void next(const size_t ) = 0;
    
    virtual bool is_number(char ) const = 0;
    virtual bool is_string(char ) const = 0;
    virtual bool is_char(char ) const = 0;
    virtual bool is_word(char ) const = 0;
    virtual bool is_oprt(char ) const = 0;
    virtual bool is_end(char ) const = 0;
    virtual bool is_null_space(char ) const = 0;
    virtual bool is_comment(char ) const = 0;
};


#endif // !_LEXER_GRAMMAR_H_
