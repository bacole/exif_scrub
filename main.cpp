#include<iostream>
#include<filesystem>
#include<string>
#include"io.h"
#include"scrub.h"

int main(int argc, char** argv){

    auto input = arg_parse(argc, argv);
    if(input.from_dir){
        for(auto dir_entry: std::filesystem::directory_iterator(input.in_path)){
            std::string file = dir_entry.path().filename();
            if(file.find(".jpg") != std::string::npos || file.find(".jpeg") != std::string::npos){
                process_image(file, input);
            }
        }
    } else{
        process_image(input.in_path, input);
    }
    return 0;

}