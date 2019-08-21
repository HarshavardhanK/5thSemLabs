#include <iostream>

#include "time_functions.h"
#include "generate.hpp"

bool contains(std::string str_, std::string find) {

    bool found = false;

    int str_len = str_.size();
    int find_len = find.size();

    for(int i = 0; i <= str_len - find_len; i++) {

        int j;

        for(j = 0; j < find_len; j++) {

            if(str_[i + j] != find[j]) 
                break;
        }

            if(j == find_len) {
                found = true;
            }
        
    }

    return found;
}

void test_string_search() {

    std::string str_ = generate_string(1000);
    //std::cout << str_ << std::endl;
    std::string find = generate_string(307);
    std::cout << "\n";
    //std::cout << find << std::endl;

    if(contains(str_, find)) {
        std::cout << "Found\n";
    } else {
        std::cout << "Not found\n"; 
    }
    
}

int main(int argc, char** argv) {

    std::cout << time_taken(test_string_search) << "s\n";


    return 0;
}