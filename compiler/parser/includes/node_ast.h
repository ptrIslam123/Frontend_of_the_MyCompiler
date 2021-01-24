#ifndef _NODE_AST_H
#define _NODE_AST_H

#include "../../lexer/includes/token.h"
#include "ast_type.h"

struct node_ast;
using ast_t = AST_TYPE;
using token_t = token*;
using node_t = node_ast*;

struct node_ast
{
public:
    node_ast(ast_t&& );
    ~node_ast();

    void set_loprnd(node_t );
    void set_roprnd(node_t );
    void set_value(token_t );

    const node_t get_loprnd() const;
    const node_t get_roprnd() const;
    token_t get_value() const;

private:
    node_t loprnd_;
    node_t roprnd_;
    token_t value_; 
    ast_t type_;
};



#endif // !_NODE_AST_H
