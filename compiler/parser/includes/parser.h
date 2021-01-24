#ifndef _PARSER_H_
#define _PARSER_H_

#include <memory>
#include "ast.h"

template<typename C>
class parser
{
    using container_t = C;
    using ast_ptr = std::unique_ptr<ast>;
public:
    parser(container_t&& , ast_ptr&& );
    
    void run();




private:
    ast_ptr ast_;
    container_t tokens_;
};


template<typename C>
parser<C>::parser(container_t&& tokens, ast_ptr&& ast):
    tokens_(std::move(tokens)),
    ast_(std::move(ast))
{}

template<typename C>
void parser<C>::run()
{
   
}

#endif // !_PARSER_H_
