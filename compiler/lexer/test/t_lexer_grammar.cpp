#include "t_lexer_grammar.h"

#include <iostream>

using namespace std;

void t_tokenize_number(std::string&& text)
{
    cout << "code = [" << text << " ]\t\t";
    auto lex = create_lex_grammar(std::move(text));
    auto tok_num = lex->tokenize_number();
    cout << "token_number =[  " << tok_num->get_value() << " ]\n";
    TokenType type = tok_num->get_type();
}

void t_tokenize_string(std::string&& text)
{
    cout << "code = [" << text << " ]\t\t";
    auto lex = create_lex_grammar(std::move(text));
    auto tok_num = lex->tokenize_string();
    cout << "token_string =[  " << tok_num->get_value() << " ]\n";
    TokenType type = tok_num->get_type();
}

void t_tokenize_word(std::string&& text)
{
    cout << "code = [" << text << " ]\t\t";
    auto lex = create_lex_grammar(std::move(text));
    auto tok_num = lex->tokenize_word();
    cout << "token_word =[  " << tok_num->get_value() << " ]\n";
    TokenType type = tok_num->get_type();
}

void t_tokenize_char(std::string&& text)
{
    cout << "code = [" << text << " ]\t\t";
    auto lex = create_lex_grammar(std::move(text));
    auto tok_num = lex->tokenize_char();
    cout << "token_char =[  " << tok_num->get_value() << " ]\n";
}

void t_tokenize_operator(std::string&& text)
{
    cout << "code = [" << text << " ]\t\t";
    auto lex = create_lex_grammar(std::move(text));
    auto tok_num = lex->tokenzie_operator();
    cout << "token_operator =[  " << tok_num->get_value() << " ]\n";
    TokenType type = tok_num->get_type();
}