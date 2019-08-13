#include <iostream>
#include "generate.hpp"

void selection_sort(int* array, unsigned int size, int* op_count) {

    *op_count = 0;

    for(int i = 0; i < size; i++) {

        int min_index = i;

        for(int j = i + 1; j < size; j++) {

            (*op_count)++;

            if(array[j] < array[min_index]) {
                min_index = j;
            }
        }

        std::swap(array[i], array[min_index]);
    }
}

int main(int argc, char** argv) {

    int size;

    std::cout << "Enter size: "; std::cin >> size;

    int* arr = new int[size];

    int op_count;

    generate_array(arr, size, -23, 100);

    print_array(arr, size);

    selection_sort(arr, size, &op_count);

    print_array(arr, size);

    std::cout << '\n';

    std::cout << "Executed in: " << op_count << " steps\n";

    return 0;
}