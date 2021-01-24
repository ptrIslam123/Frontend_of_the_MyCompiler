#ifndef _LEXER_H_
#define _LEXER_H_

#include <iostream>
#include <memory>
#include "token.h"
#include "lexer_grammar.h"



template<typename C, typename F>
class lexer
{
public:
    using container_t = C;
    using func_t = F;
    using lex_grammar_t = std::unique_ptr<lexer_grammar>;
public:
    lexer(func_t , lex_grammar_t&& );
    container_t&& get_container();
    void run();

private:
    void push_back(token* );
    void undefine_token();

private:
    lex_grammar_t lex_grammar_;
    container_t container_;
    func_t make_token_;
};


template<typename C, typename F>
lexer<C,F>::lexer(func_t func, lex_grammar_t&& lex_grammar):
    make_token_(func),
    lex_grammar_(std::move(lex_grammar))
{}

template<typename C, typename F>
typename lexer<C,F>::container_t&& lexer<C,F>::get_container()
{
    return std::move(container_);
}

template<typename C, typename F>
void lexer<C,F>::push_back(token* token_ptr)
{ 
    container_.push_back(
        make_token_(token_ptr)
    );
}

template<typename C, typename F>
void lexer<C,F>::undefine_token()
{
    std::cout << "erorr: undefine token\n\n";
    throw "undefine token\n";
}

template<typename C, typename F>
void lexer<C,F>::run()
{
    char s;
    while (!lex_grammar_->is_end( lex_grammar_->get(0) ))
    {
        s = lex_grammar_->get(0);

        if ( lex_grammar_->is_comment(s) )
        {
            lex_grammar_->tokenize_comment();
            continue;
        }
        else if ( lex_grammar_->is_string(s) )
        {
            push_back( lex_grammar_->tokenize_string() );
            continue;
        }
        else if ( lex_grammar_->is_char(s) )
        {
            push_back( lex_grammar_->tokenize_char() );
            continue;
        }
        else if ( lex_grammar_->is_number(s) )
        {
            push_back( lex_grammar_->tokenize_number() );
            continue;
        }
        else if ( lex_grammar_->is_word(s) )
        {
            push_back( lex_grammar_->tokenize_word() );
            continue;
        }
        else if ( lex_grammar_->is_oprt(s) )
        {
            push_back( lex_grammar_->tokenzie_operator() );
            continue;
        }
        else if ( lex_grammar_->is_null_space(s) )
        {
            lex_grammar_->next(1);
        }
        else
        {
           undefine_token();
        }
    }
}

#endif // !_LEXER_H
