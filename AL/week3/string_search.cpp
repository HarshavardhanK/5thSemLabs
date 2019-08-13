#include <iostream>
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

int main(int argc, char** argv) {

    std::string str_ = "abcdecdecdefgcde";
    std::string find = "gcde";

    if(contains(str_, find)) {
        std::cout << "Found\n";
    } else {
        std::cout << "Not found\n"; 
    }

    return 0;

    return 0;
}