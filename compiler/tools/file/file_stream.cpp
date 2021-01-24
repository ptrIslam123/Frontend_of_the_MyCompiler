#include "includes/file_stream.h"
#include <iostream>

file_stream::file_stream(std::string&& file_name)
{
    file_name_ = std::move(file_name);
    ifstream_.open(std::move(file_name_));
    is_ofstream_create_ = false;
}

file_stream::file_stream(const std::string& file_name)
{
    file_name_ = file_name;
    ifstream_.open(std::move(file_name_));
    is_ofstream_create_ = false;
}

file_stream::~file_stream()
{
    ifstream_.close();
    if(is_ofstream_create_)
    {
        ofstream_.close();
    }
}

bool file_stream::file_is_open() const
{
    return ifstream_.is_open();
}

std::string file_stream::readf()
{
    std::string buffer;
    char s;
    while (ifstream_.get(s))
    {
        buffer += s;
    }
    return buffer;
}

bool file_stream::create_file()
{
    ofstream_.open(file_name_);
    is_ofstream_create_ = true;
    return true;
}

void file_stream::writef(const std::string& data)
{
    if (!is_ofstream_create_)
    {
        ofstream_.open(file_name_);
        is_ofstream_create_ = true;
    }
    ofstream_ << data;
}

void file_stream::writef(std::string&& data)
{
    if (!is_ofstream_create_)
    {
        ofstream_.open(file_name_);
        is_ofstream_create_ = true;
    }
    ofstream_ << data;
}

void file_stream::append(std::string&& data)
{
    
}

void file_stream::append(const std::string& data)
{
    
}


