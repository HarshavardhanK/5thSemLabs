#include "process.h"
#include "queue.h"

#include <unistd.h>

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

void round_robin(QUEUE* queue) {

    int total = 10;

    float wait = 0.0;

    sleep(front(queue)->burst);

    dequeue(queue);


    while(1) {

        dequeue(queue);

        PROC* curr = front(queue);
        sleep(curr->burst);
        
        //wait += curr->burst;
        wait += total - front(queue)->arrival;
        total += 10;

        if(is_empty(queue)) {
            break;
        }
    }

    printf("Wait time is %.2f\n", wait);
}

void shortest_remaining_time(QUEUE* input_queue, QUEUE* output_queue, int size) {

    if(input_queue == NULL || output_queue == NULL) {
        printf("Queue empty for preemptive sjf");
        return;
    }

    float waiting_time;

    while(1) {
        
    }

}

void input_process() {

    int size;

    QUEUE* queue = create_queue(10, 3);

    printf("Enter process in ascending order\n");
    printf("Enter number of process: "); scanf("%d", &size);

    PROC* arr[size];

    for(int i = 0; i < size; i++) {
        printf("Enter for process %d\n", i);

        int arrival, burst, priority;
        scanf("%d", &arrival); scanf("%d", &burst); scanf("%d", &priority);

        PROC* p = create_process(burst, arrival, priority);

        arr[i] = p;

        enqueue(queue, p);
    }

    printf("FCFS\n");
    fcfs(arr, size);
    //print_queue(queue);

    printf("RR\n");
    round_robin(queue);
    

}


int main() {

    input_process();

    return 0;
}

