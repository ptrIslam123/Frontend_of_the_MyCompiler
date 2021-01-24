#ifndef _CREATE_OBJ_H_
#define _CREATE_OBJ_H_

#include <vector>
#include <memory>

#include "../includes/lexer_tokens_grammar.h"
#include "../includes/lexer_grammar.h"
#include "../includes/lexer_grammar_type.h"
#include "../includes/lexer.h"
#include "../includes/token.h"

using lex_gramm_ptr =  std::unique_ptr<lexer_tokens_grammar>;
using lexer_grammar_ptr = std::unique_ptr<lexer_grammar>;

using token_ptr = std::unique_ptr<token>;

lexer_grammar_ptr create_lexer_grammar
(LexerGrammarType&& , std::string&&);

lex_gramm_ptr create_lex_grammar(std::string&& );

token_ptr create_token(std::string&& , TokenType&& );

#endif // !_CREATE_OBJ_H_
