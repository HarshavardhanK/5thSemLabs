#include <iostream>
#include <string>
#include "generate.hpp"
using namespace std;

void bubble_sort(int* arr, int size, int* op_count) {

    *op_count = 0;

    for(int i = 0; i < size - 1; i++) {

        for(int j = 0; j < size - i - 1; j++) {

            (*op_count)++;

            if(arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}

int main(int argc, char** argv) {

    int size; 
    
    cout << "Enter size: "; cin >> size;

    int *arr = new int[size];

    generate_array(arr, size, -20, 100);
    print_array(arr, size);

    int op_count = 0;

    bubble_sort(arr, size, &op_count);

    print_array(arr, size);

    cout << "Op count: " << op_count <<'\n';

    return 0;


    return 0;
}