#include <iostream>
#include "file/includes/file_stream.h"

#include <fstream>
#include <string>


int main()
{
    std::string file_name 
    = "/home/islam/CppProgram/compiler/LiScript/compiler/tools/file.txt";
    
    
    file_stream f(file_name);

    std::cout << f.readf() << "\n";
    f.writef("new data!");

    //std::cout << f.readf() << "\n";

    return 0;
}