#ifndef SOLUTION
#define SOLUTION

#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;


bool isFolderValid(const fs::path& dir) {
    // your code here ...
    if(!fs::exists(dir)) return false;

    if(fs::is_regular_file(dir)) return fs::file_size(dir) > 0 ;

    if(fs::is_directory(dir)) {
        if(fs::is_empty(dir)) return false;
        for(const auto& entery: fs::directory_iterator(dir)) {
            if(!isFolderValid(entery.path())) return false;
        }
        return true;
    }
    return false;
 }
     

#endif