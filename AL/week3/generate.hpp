#ifndef GENERATE_HPP
#define GENERATE_HPP

#include <stdlib.h>
#include <time.h>

template <typename T> void print_array(T* arr, int size) {

    if(arr == NULL) {
        std::cout << "Invalid array\n";
        return;
    }

    for(int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    
    std::cout << '\n';
}

void generate_array(int* array, int size, int begin, int end) {

    for(int i = 0; i < size; i++) {
        array[i] = rand() % (end - begin) + begin; 
    }
}

std::string generate_string(int size) {

    std::string str_;
    srand(time(0));

    for(int i = 0; i < size; i++) {
        
        str_.push_back(char(rand() % 26 + 65));
    }

    return str_;

}


#endif