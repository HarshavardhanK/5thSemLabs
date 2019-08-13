#include <stdio.h>
#include <stdlib.h>

int gcd(int m, int n) {

    int n_copy = n;

    while(1) {

        if(m % n == 0) {
            
            if(n_copy % n == 0)
                return n;
        } 

        n--;

    }

    return -1;
}

int middle_school(int m, int n) {

    int i = 2;
    int prod = 1;

    while(i < n) {

        int m_ = m % i;
        int n_;

        if(m_ == 0) {
            m /= i;
            i--;
        }

        if(i <= n) {
            n_ = n % i;

            if(n_ == 0) {
                n /= i;
                i--;
            }
                
        }
           
        if(m_ == 0 && n_ == 0) {
            prod *= i;
        }

        if(m == 0 && n == 0)
            return prod;

        i++;
    }
}

 int get_common_multiplied(int *arr1, int *arr2, int size1, int size2) {

    int prod = 1;

    int i, j = 0;

    while(i < size1 && j < size2) {

        if(arr1[i] == arr2[j]) {
            prod *= arr1[i];
            i++;j++;
        }
    }

    return prod;

}

/*int gcd_middle(int m, int n) {

    int *f_m = (int*) malloc(sizeof(int) * m);
    int *f_n = (int*) malloc(sizeof(int) * n);

    int size_m, size_n;

    get_factors(f_m, m, &size_m); get_factors(f_n, n, &size_n);
    printf("size %d\n", size_m);

    //return get_common_multiplied(f_m, f_n, size_m, size_n);
} */

int main(int argc, char** argv) {

    int g = middle_school(10, 6);
    printf("%d\n", g);

    return 0;
}