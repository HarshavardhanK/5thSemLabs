#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int segmentation(int limit[], int base[], int size, int seg, double offset) {

    double power = ceil((log(limit[seg]) / log(2))); 
    double limit_ = pow(2.0, power);

    int phy_arr = base[seg] + offset;
    int page = ceil(offset / 512.0);

    printf("Physical address: %d Page num: %d ", phy_arr, page);

    if(phy_arr > limit_ + base[seg]) {
        printf("Illegal access\n");
        return -1;

    } else {
        printf("Legal access\n");
    }

    return phy_arr;
}

int main() {

    int size;
    printf("Enter size limit and base array: ");
    scanf("%d", &size);

    int limit[size], base[size];

    printf("Enter limit array: \n");

    for(int i = 0; i < size; i++) {
        int g;
        scanf("%d", &g);

        if(g > 0) {
            limit[i] = g;
        }
    }

    printf("Enter base array: \n");

    for(int i = 0; i < size; i++) {
        int g;
        scanf("%d", &g);

        if(g > 0) {
            base[i] = g;
        }
    }

    int seg = 0;

    printf("Enter segment num: "); scanf("%d", &seg);
    
    int offset = 928;
    printf("Enter offset: "); scanf("%d", &offset);

   int segm = segmentation(limit, base, size, seg, offset);

   printf("\n");

    //printf("%.2f\n", (log(100) / log(2)));

    return 0;
}