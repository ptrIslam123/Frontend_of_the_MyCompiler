#ifndef _PARSER_METHODS_H_
#define _PARSER_METHODS_H_

#include <memory>
#include <string>
#include <vector>

#include "../../lexer/includes/lexer_methods.h"

using token_type_std = std::unique_ptr<token>;
using container_type_std = std::vector<token_type_std>;

auto get_tokens(std::string&& );

auto get_tokens(std::string&& text)
{
   auto make_token = [](auto token_ptr)
   {
       return std::unique_ptr<token>(token_ptr);
   };

   auto lex_grammar = 
    make_lexer_tokens_grammar(std::move(text));

   return get_result_lexer<container_type_std, decltype(make_token)>
                (make_token, std::move(lex_grammar));
}


#endif // !_PARSER_METHODS_H_
