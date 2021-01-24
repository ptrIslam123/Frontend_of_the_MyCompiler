#include "includes/token.h"

token::token(token_value&& value, token_type&& type):
    value_(value), type_(type) {}

token::~token() {}

const token::token_value& token::get_value()
{
    return value_;
}

const token::token_type& token::get_type()
{
    return type_;
}

