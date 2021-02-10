#ifndef IO
#define IO

#include<vector>
#include<string>
#include<fstream>
#include<cstring>

std::vector<char> read_bytes(const std::string& path);

void write_bytes(const std::string& path, const std::vector<char>& buffer);

struct args
{
    std::string in_path;
    std::string out_path;
    bool bu;
    bool from_dir;
    bool to_dir;
    bool verbose;
};

args arg_parse(int argc, char** argv);

#endif