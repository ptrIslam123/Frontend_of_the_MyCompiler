#ifndef _BASE_aST_H_
#define _BASE_aST_H_

#include <iostream> // for size_t
#include <memory>
#include <iterator>
#include "ast.h"
#include "../../lexer/includes/token.h"

template<typename C>
class base_ast : public ast
{
protected:
    using container_t = C;
    using container_iter_t = typename container_t::iterator;

public:
    base_ast(container_t&& );
    ~base_ast();

protected:
    token_t get(size_t );
    void next(size_t );
 

private:
    container_t tokens_;
    container_iter_t pos_;
    container_iter_t end_;
    token_t null_token;
};


template<typename C>
base_ast<C>::base_ast(container_t&& tokens)
{
    tokens_ = std::move(tokens);
    pos_ = tokens_.begin();
    end_ = tokens_.end();
    null_token = nullptr;
}

template<typename C>
base_ast<C>::~base_ast() 
{
#ifdef TEST_WR_DEBUG_INF
    WR_DEBUG_INF("~base_ast()");
#endif // !TEST_WR_DEBUG_INF
}


template<typename C>
token_t base_ast<C>::get(size_t rel_position)
{
    std::advance(pos_, rel_position);
    if (pos_ >= end_)
    {
        return null_token;
    }
    return (*pos_).get();
}

template<typename C>
void base_ast<C>::next(size_t offset)
{
    std::advance(pos_, offset);
}

#endif // !_BASE_aST_H_
