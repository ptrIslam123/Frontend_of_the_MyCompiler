#ifndef _EXPR_AST_H_
#define _EXPR_AST_H_

#include <memory>
#include "base_ast.h"

template<typename C>
class expresiion_ast : public base_ast<C>
{
    using container_t = C;
public:
    expresiion_ast(container_t&& );
    ~expresiion_ast();

    virtual node_t build() override;

private:

private:

};


template<typename C>
expresiion_ast<C>::expresiion_ast(container_t&& tokens):
    base_ast<C>( std::move(tokens) )
{}

template<typename C>
expresiion_ast<C>::~expresiion_ast()
{
#ifdef TEST_WR_DEBUG_INF
    WR_DEBUG_INF("~expression_ast()");
#endif // !TEST_WR_DEBUG_INF
}


template<typename C>
node_t expresiion_ast<C>::build()
{
    return nullptr;
}

#endif // !_EXPR_AST_H_
