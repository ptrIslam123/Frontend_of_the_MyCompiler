#include "includes/node_ast.h"

node_ast::node_ast(ast_t&& type):
    type_(type),
    loprnd_(nullptr),
    roprnd_(nullptr),
    value_(nullptr)
{}

node_ast::~node_ast()
{

}

void node_ast::set_loprnd(node_t loprnd)
{
    loprnd_ = loprnd;
}

void node_ast::set_roprnd(node_t roprnd)
{
    roprnd_ = roprnd;
}

void node_ast::set_value(token_t value)
{
    value_ = value;
}

const node_t node_ast::get_loprnd() const
{
    return loprnd_;
}


const node_t node_ast::get_roprnd() const
{
    return roprnd_;
}


token_t node_ast::get_value() const
{
    return value_;
}

