#include"io.h"


std::vector<char> read_bytes(const std::string& path){

    std::vector<char> buffer;
    std::ifstream in_file(path, std::ios_base::binary);
    //get file size
    in_file.seekg(0, std::ios_base::end);
    size_t length = in_file.tellg();
    in_file.seekg(0, std::ios_base::beg);
    if(length > 0)
        buffer.reserve(length);
    //read file
    std::copy( std::istreambuf_iterator<char>(in_file),
            std::istreambuf_iterator<char>(),
            std::back_inserter(buffer) );
    in_file.close();
    return buffer;
}



void write_bytes(const std::string& path, const std::vector<char>& buffer){

    std::ofstream out_file(path, std::ios_base::out | std::ios_base::binary);
    out_file.write((char*)&buffer[0], buffer.size() * sizeof(char));
    out_file.close();

}



args arg_parse(int argc, char** argv){
    args parsed_args;
    std::string path(argv[1]);
    parsed_args.in_path = path;
    parsed_args.bu = false;
    parsed_args.to_dir = true;
    parsed_args.from_dir = true;
    parsed_args.verbose = false;
    parsed_args.out_path = "";

    if(path.find(".jpg") != std::string::npos || path.find(".jpeg") != std::string::npos){
        parsed_args.from_dir = false;
    } 
    for(int i(2); i < argc; ++i){
        if(strcmp(argv[i], "-bu") == 0){
            parsed_args.bu = true;
        }
        if(strcmp(argv[i], "-o") == 0){
            std::string out_path(argv[i+1]);
            parsed_args.out_path = out_path;
            if(out_path.find(".jpg") != std::string::npos || out_path.find(".jpeg") != std::string::npos){
                parsed_args.to_dir = false;
            }
            ++i;
        }
        if(strcmp(argv[i], "-v") == 0){
            parsed_args.verbose = true;
        }
    }
    return parsed_args;
}