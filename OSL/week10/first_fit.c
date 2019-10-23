#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_allocations(int* allocation, int *proc_mem, int num_proc) {

    printf("PNo\tPSize\tBlock no\n");

    for(int i = 0; i < num_proc; i++) {
        printf("%d\t%d\t", i + 1, proc_mem[i]);

        if(allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not allocated\n");
    }

}

void first_fit(int *memory_bloks, int num_mem, int* proc_mem, int num_proc) {

    int allocation[num_proc];

    memset(allocation, -1, sizeof(allocation));

    for(int i = 0; i < num_proc; i++) {

        for(int j = 0; j < num_mem; j++) {

            if(memory_bloks[j] >= proc_mem[i]) {
                allocation[i] = j;
                memory_bloks[j] -= proc_mem[i];

                break;
            }
        }
    }

    printf("Process no\tProcess size\nBlock no\n");

    for(int i = 0; i < num_proc; i++) {
        printf("%d\t%d\t", i + 1, proc_mem[i]);

        if(allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not allocated\n");
    }
}

void best_fit(int *memory_bloks, int num_mem, int* proc_mem, int num_proc) {

    int allocation[num_proc];
    int best_indx = -1;

    memset(allocation, -1, sizeof(allocation));

    for(int i = 0; i < num_proc; i++) {

        for(int j = 0; j < num_mem; j++) {

            if(proc_mem[i] <= memory_bloks[j]) {

                if(best_indx == -1)
                    best_indx = j;
                else if(memory_bloks[best_indx] > memory_bloks[j])
                    best_indx = j;
            }
        }

        if(best_indx != -1)
            allocation[i] = best_indx;
            memory_bloks[best_indx] -= proc_mem[i];
    }

    print_allocations(allocation, proc_mem, num_proc);

}

void wrst_fit(int *memory_bloks, int num_mem, int* proc_mem, int num_proc) {

    int allocation[num_proc];
    int wrst_indx = -1;

    memset(allocation, -1, sizeof(allocation));

    for(int i = 0; i < num_proc; i++) {

        for(int j = 0; j < num_mem; j++) {

            if(proc_mem[i] <= memory_bloks[j]) {

                if(wrst_indx == -1)
                    wrst_indx = j;
                else if(memory_bloks[wrst_indx] < memory_bloks[j])
                    wrst_indx = j;
            }
        }

        if(wrst_indx != -1)
            allocation[i] = wrst_indx;
            memory_bloks[wrst_indx] -= proc_mem[i];
    }

    print_allocations(allocation, proc_mem, num_proc);

}

int main(int argc, char** argv) {

    int num_mem, num_proc;

    printf("Enter num memory blocks: "); scanf("%d", &num_mem);
    printf("Enter num procs: "); scanf("%d", &num_proc);

    int *proc_mem = (int*) malloc(sizeof(int) * num_proc);
    int *mem_blok = (int*) malloc(sizeof(int) * num_mem);

    for(int i = 0; i < num_mem; i++) {
        printf("Enter mem blok size: "); scanf("%d", &mem_blok[i]);
    }

    for(int i = 0; i < num_proc; i++) {
        printf("Enter proc blok size: "); scanf("%d", &proc_mem[i]);
    }

   // first_fit(mem_blok, num_mem, proc_mem, num_proc);

    printf("Best fit\n");

    wrst_fit(mem_blok, num_mem, proc_mem, num_proc);

    return 0;

    
}