#ifndef _LEXER_TOKENS_GRAMMAR_H_
#define _LEXER_TOKENS_GRAMMAR_H_

#include <iostream>
#include <string>
#include <memory>

#include "lexer_grammar.h"
#include "token.h"


class lexer_tokens_grammar : public lexer_grammar
{
public:
     lexer_tokens_grammar(std::string&& );
    ~lexer_tokens_grammar();

    virtual token* tokenize_number() override;
    virtual token* tokenize_string() override;
    virtual token* tokenize_char() override;
    virtual token* tokenize_word() override;
    virtual token* tokenzie_operator() override;
    virtual void tokenize_comment() override;
    virtual char get(const size_t ) override;
    virtual void next(const size_t ) override;

    virtual bool is_number(char ) const override;
    virtual bool is_string(char ) const override;
    virtual bool is_char(char ) const override;
    virtual bool is_word(char ) const override;
    virtual bool is_oprt(char ) const override;
    virtual bool is_end(char ) const override;
    virtual bool is_null_space(char ) const override;
    virtual bool is_comment(char )const  override;

private:
    token* create_token(std::string&& , TokenType&& );
    token* double_oprt(const char );
    token* once_oprt(const char );
    bool is_double_oprt(char ) const;
    bool is_letter(char ) const;

private:
    std::string text_code_;
    size_t pos_;
    size_t size_text_;
};

#endif // !_LEXER_TOKENS_GRAMMAR_H_
