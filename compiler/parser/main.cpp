#include <iostream>
#include <string>

#include <vector>
#include <list>

//#include "includes/parser.h"
#include "includes/base_ast.h"
#include "includes/ast.h"
#include "includes/node_ast.h"
#include "includes/expression_ast.h"

#include "includes/parser_methods.h"






int main()
{
    std::string text = "x = a + b";
    
    auto tokens = 
        get_tokens(std::move(text));
    

        
    expresiion_ast<container_type_std>
        expr(std::move(tokens));

    
    
    return 0;
}