#include"scrub.h"

const uint8_t exif_header[] = {0x45, 0x78, 0x69, 0x66, 0x00, 0x00};

void scrub(std::vector<char>& buffer, const args& input){
    int exif_count(0), changes(0);
    bool marker(false), exif(false);
    for(size_t i(0); i < buffer.size(); ++i){
        auto byte = buffer[i];
        if((uint8_t) byte == 0xff){
            //JPEG marker 
            exif = false;
            marker = true;
            continue;
        } else if((uint8_t) byte == 0xe1){
            //APP1 marker 
            if(marker){
                //check for exif header 
                if(memcmp(&exif_header, &buffer[i+3], 6) == 0){
                    exif = true;
                    marker = false;
                    exif_count++;
                    
                    i += 8;
                }
            }
            continue;
        } else {
            if(exif){
                buffer[i] = 0x00;
                changes++;
            } 

        }
    }
    if(input.verbose)
        std::cout << "exif chunks found: " << exif_count << " changes made: " << changes << '\n';
}



void process_image(const std::string& img_path, const args& input){
    auto image = read_bytes(img_path);
    if(input.bu){
        auto bu_path = img_path;
        bu_path.insert(bu_path.find(".jp"), "_bu");
        write_bytes(bu_path, image);
    }
    scrub(image, input);
    if(input.out_path != ""){
        if(input.to_dir){
            write_bytes(input.out_path + img_path, image);
        } else{
            write_bytes(input.out_path, image);
        }
    } else{
        write_bytes(img_path, image);
    }    
}