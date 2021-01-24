#include "create_obj.h"

#include "create_obj.h"

lexer_grammar_ptr create_lexer_grammar
(LexerGrammarType&& lex_type, std::string&& text)
{
    if (lex_type == LexerGrammarType::STD)
    {
        return std::unique_ptr<lexer_grammar>(
            new lexer_tokens_grammar(std::move(text))
        );
    }
    else return nullptr;
}

lex_gramm_ptr create_lex_grammar(std::string&& text)
{
    return std::make_unique<lexer_tokens_grammar>(std::move(text));
}

token_ptr create_token(std::string&& value, TokenType&& type)
{
    return std::make_unique<token>(
        std::move(value), std::move(type)
    );
}