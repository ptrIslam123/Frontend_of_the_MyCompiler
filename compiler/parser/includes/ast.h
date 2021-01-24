#ifndef _AST_H
#define _AST_H
#define TEST_WR_DEBUG_INF
#define WR_DEBUG_INF(MSG) std::cout << MSG <<"\n\n"

#include <iostream>
#include "node_ast.h"

class ast
{
public:
    virtual node_t build() = 0;
    virtual ~ast();
};

ast::~ast()
{
#ifdef TEST_WR_DEBUG_INF
    WR_DEBUG_INF("~ast()");
#endif // !TEST_WR_DEBUG_INF
}

#endif // !_AST_H
