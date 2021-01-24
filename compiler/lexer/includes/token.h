#ifndef _TOKEN_H_
#define _TOKEN_H_

#include <string>
#include "token_type.h"

class token
{
public:
    typedef std::string token_value;
    typedef TokenType token_type;

public:
    token(token_value&& , token_type&& );
    ~token();

    const token_value& get_value();
    const token_type& get_type();


private:
    token_value value_;
    token_type type_;
};

#endif // !_TOKEN_H_
