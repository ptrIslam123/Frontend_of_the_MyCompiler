#ifndef _AST_TYPE_H
#define _AST_TYPE_H

enum class AST_TYPE
{
    EXPR,
    CALL_FUNC,
    PARAM_LIST,
    ARG_LIST,
    BLOCK,
    IF,
    ELSE,
    WHILE,
    FACT,
    TERM,
    LOG_F,
    COND
};

#endif // !_AST_TYPE_H
