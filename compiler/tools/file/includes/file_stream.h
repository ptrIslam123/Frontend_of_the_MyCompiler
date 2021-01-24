#ifndef _FILE_STREAM_H_
#define _FILE_STREAM_H_

#include <string>
#include <fstream>

class file_stream
{
public:
    file_stream(const std::string& );
    file_stream(std::string&& );
    ~file_stream();

    bool file_is_open() const;
    bool create_file();

    std::string readf();
    void writef(std::string&& );
    void writef(const std::string& );
    void append(std::string&& );
    void append(const std::string& );

private:
    bool is_ofstream_create_; 
    std::string file_name_;
    std::ofstream ofstream_;
    std::ifstream ifstream_;
};

#endif // !_FILE_STREAM_H_
