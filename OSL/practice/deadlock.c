#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void vector_add(int* A, int* B, int size) {

    for(int i = 0; i < size; i++) {
        A[i] += B[i];
    }
} 

int vector_lesser(int* A, int* B, int size) {

    for(int i = 0;  i < size; i++) {
        if(A[i] > B[i]) {
            return 0;
        }
    }

    return 1;

}

void vector_copy(int* A, int* B, int size) {

    for(int i = 0; i < size; i++)
        A[i] = B[i];
}

int vector_equal(int* A, int value, int size) {

    for(int i = 0; i < size; i++)
        if(A[i] != value)
            return 0;
    
    return 1;
}

//returns the values in matrix result

void matrix_sub(int** A, int** B, int** result, int rows, int cols) {

    for(int i = 0; i < rows; i++) {

        for(int j = 0; j < cols; j++) {

            result[i][j] = A[i][j] - B[i][j];

        }
    }

}

int bankers_safety(int* available, int** max, int** allocation, int num_proc, int num_resourc) {

    // num_proc x num_resourc matrix.. num_resourc vector len except finish len num_proc (wrt process)

    int** need = (int**) malloc(sizeof(int*) * num_proc);

    for(int i = 0; i < num_proc; i++)
        need[i] = (int*) malloc(sizeof(int) * num_resourc);

    
     //Need = Max - Allocation

    matrix_sub(max, allocation, need, num_proc, num_resourc);

    int* work = (int*) malloc(sizeof(int) * num_resourc);

    //work = available
    vector_copy(work, available, num_resourc);

    int finish[num_proc];//= (int*) malloc(sizeof(int) * num_proc);
    memset(finish, 0, sizeof(finish));

    int safe_sequence[num_proc];
    int safe_count = 0;

    for(int i = 0; i < num_proc; i++) {

        if(!finish[i] && vector_lesser(need[i], work, num_resourc)) {

            vector_add(work, allocation[i], num_resourc); 
            safe_sequence[safe_count++] = i;
            finish[i] = 1;
        }
    }

    if(vector_equal(finish, 1, num_proc)) {

        printf("Safe sequence is\n");

        for(int i = 0; i < safe_count; i++)
            printf("%d ", safe_sequence[i]);

        printf("\n");

        return 1;
    }

    return 0;

}

int is_deadlocked(int* available, int** request, int** allocation, int num_proc, int num_resourc) {

    int* work = (int*) malloc(sizeof(int) * num_resourc);

    int finish[num_proc];

    vector_copy(work, available, num_resourc);

    for(int i = 0; i < num_proc; i++) {

        if(!vector_equal(allocation[i], 0, num_resourc)) {
            finish[i] = 0;

        } else {
            finish[1] = 1;
        }
    }

    for(int i = 0; i < num_proc; i++) {

        if(!finish[i] && vector_lesser(request[i], work, num_resourc)) {
            vector_add(work, allocation[i], num_resourc);
            finish[i] = 1;
        }
    }

    if(!vector_equal(finish, 1, num_proc)) {
        return 1;
    }

    return 0;
    
    
}

void run_bankers() {

    printf("Enter num process: ");
    int num_proc;
    scanf("%d", &num_proc);

    printf("Enter num resources: ");
    int num_resourc;
    scanf("%d", &num_resourc);

    int* available = (int*) malloc(sizeof(int) * num_resourc);

    int** max = (int**) malloc(sizeof(int*) * num_proc);

    for(int i = 0; i < num_proc; i++)
        max[i] = (int*) malloc(sizeof(int) * num_resourc);

    int** allocation = (int**) malloc(sizeof(int*) * num_proc);

    for(int i = 0; i < num_proc; i++)
        allocation[i] = (int*) malloc(sizeof(int) * num_resourc);

    printf("Enter available of each type\n");
    for(int i = 0; i < num_resourc; i++) {
        printf("Type %d: ", i);
        scanf("%d", &available[i]);
    }

    printf("Enter max matrix: \n");
    for(int i = 0; i < num_proc; i++)
        for(int j = 0; j < num_resourc; j++)
            scanf("%d", &max[i][j]);

    printf("Enter allocation matrix\n");
    for(int i = 0; i < num_proc; i++)
        for(int j = 0; j < num_resourc; j++)
            scanf("%d", &allocation[i][j]);

    
    if(bankers_safety(available, max, allocation, num_proc, num_resourc)) {
        printf("System in safe state\n");

    } else {
        printf("System unsafe\n");
    }


}

void run_deadlock_detection() {

    printf("Enter num process: ");
    int num_proc;
    scanf("%d", &num_proc);

    printf("Enter num resources: ");
    int num_resourc;
    scanf("%d", &num_resourc);

    int* available = (int*) malloc(sizeof(int) * num_resourc);

    int** request = (int**) malloc(sizeof(int*) * num_proc);

    for(int i = 0; i < num_proc; i++)
        request[i] = (int*) malloc(sizeof(int) * num_resourc);

    int** allocation = (int**) malloc(sizeof(int*) * num_proc);

    for(int i = 0; i < num_proc; i++)
        allocation[i] = (int*) malloc(sizeof(int) * num_resourc);

    printf("Enter available of each type\n");
    for(int i = 0; i < num_resourc; i++) {
        printf("Type %d: ", i);
        scanf("%d", &available[i]);
    }

    printf("Enter request matrix: \n");
    for(int i = 0; i < num_proc; i++)
        for(int j = 0; j < num_resourc; j++)
            scanf("%d", &request[i][j]);

    printf("Enter allocation matrix\n");
    for(int i = 0; i < num_proc; i++)
        for(int j = 0; j < num_resourc; j++)
            scanf("%d", &allocation[i][j]);

    
    if(!is_deadlocked(available, request, allocation, num_proc, num_resourc)) {
        printf("System not deadlocked\n");

    } else {
        printf("System deadlocked\n");
    }

}

int main() {

    run_deadlock_detection();

    
    return 0;
}