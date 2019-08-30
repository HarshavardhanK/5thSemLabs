#include "process.h"
#include "queue.h"

void fcfs(PROC* arr[], int size) {

    float average_wait = 0.0;
    int total = arr[0]->burst;

    printf("Turn around time for process %d is %d \n", 0, arr[0]->burst);
    
    if(arr) {

        for(int i = 1; i < size; i++) {
            average_wait += total - arr[i]->arrival;
            total += arr[i]->burst;

            int turn = total - arr[i]->arrival;

            printf("Turn around time for process %d is %d \n", i, turn);
        }
    }

    printf("Average waiting time is %.2f: \n", (average_wait / size));
}

void input_process() {

    int size;

    printf("Enter process in ascending order\n");
    printf("Enter number of process: "); scanf("%d", &size);

    PROC* arr[size];

    for(int i = 0; i < size; i++) {
        printf("Enter for process %d\n", i);

        int arrival, burst, priority;
        scanf("%d", &arrival); scanf("%d", &burst); scanf("%d", &priority);

        PROC* p = create_process(burst, arrival, priority);

        arr[i] = p;
    }

    fcfs(arr, size);

}


int main() {

    input_process();

    return 0;
}

