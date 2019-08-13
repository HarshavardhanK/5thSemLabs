#include <iostream>
using namespace std;

bool is_subset(int* arr, int size, int sum) {

    if(size == 0) {
        return true;
    }

    if(size == 0 && sum != 0)
        return false;

    if(arr[size - 1] > sum) {
        return is_subset(arr, size - 1, sum);
    }

    return is_subset(arr, size - 1, sum) || is_subset(arr, size - 1, sum - arr[size - 1]);
}

bool find_parition(int *arr, int size) {

    int sum = 0;
    
    for(int i = 0; i < size; i++)
        sum += arr[i];
    
    if(sum % 2 != 0)
        return false;
    
    return is_subset(arr, size, sum / 2);
}

int main(int argc, char** argv) {

    int arr[] = {3,1,5,9,12};
    int size = 5;

    if(find_parition(arr, size)) {
        std::cout << "Found 2 sets parition\n";
        
    } else {
        std::cout << "Parition not found\n";
    }

    return 0;
}