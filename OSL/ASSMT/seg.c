#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*int segmentation(int limit[], int base[], int size, int seg, double offset) {

    double power = ceil((log(offset) / log(2))); 
    offset = pow(2.0, power);

    int phy_arr = base[seg] + offset;
    int page = ceil(offset / 512.0);

    printf("Physical address: %d Page num: %d ", phy_arr, page);

    if(offset > limit[seg]) {
        printf("Illegal access\n");
        return -1;
    }

    return phy_arr;
}*/

int main() {
    int limit[] = {1000, 3000};
    int base[] = {1400, 6400};
    int seg = 0;
    int offset = 1007;
    int size = 2;

   // int segm = segmentation(limit, base, size, seg, offset);

    double power = ceil((log(offset) / log(2))); 
    offset = pow(2.0, power);

    int phy_arr = base[seg] + offset;
    int page = ceil(offset / 512.0);

    printf("Physical address: %d Page num: %d ", phy_arr, page);

    if(offset > limit[seg]) {
        printf("Illegal access\n");
        return -1;
    }

    printf("%.2f\n", (log(100) / log(2)));

    return 0;
}