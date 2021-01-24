#ifndef _LEXER_METHODS_H_
#define _LEXER_METHODS_H_

#include <memory>
#include "lexer_grammar.h"
#include "lexer_grammar_type.h"
#include "lexer_tokens_grammar.h"
#include "lexer.h"
#include "token.h"


std::unique_ptr<lexer_grammar> 
make_lexer_tokens_grammar(std::string&&);


std::unique_ptr<lexer_grammar> 
make_lexer_tokens_grammar(std::string&& text_code)
{
   return std::unique_ptr<lexer_grammar>(
       new lexer_tokens_grammar(std::move(text_code))
    );
}



template<typename C, typename F>
auto get_result_lexer(F , std::unique_ptr<lexer_grammar>&& );

template<typename C, typename F>
auto get_result_lexer
(F make_token, std::unique_ptr<lexer_grammar>&& lex_grammar)
{
    using container_type = C;
    using func_type = F;

    lexer<container_type, func_type>
        lex(make_token, std::move(lex_grammar));

    lex.run();
    return lex.get_container();
}

#endif // !_LEXER_METHODS_H_
