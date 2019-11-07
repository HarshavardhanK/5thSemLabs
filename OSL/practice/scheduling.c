#include "process.h"

float fcfs(Proc** list, int size) {

    qsort(list, size, sizeof(list[0]), comp);

    float waiting = 0.0;

    list[0]->wait = 0;
    list[0]->turn = list[0]->burst - list[0]->arrival;

    for(int i = 1;  i < size; i++) 
        list[i]->wait = list[i - 1]->wait + list[i - 1]->burst;

    for(int i = 0; i < size; i++) {
        waiting += list[i]->wait - list[i]->arrival;
        list[i]->turn = list[i]->wait + list[i]->burst - list[i]->arrival;
    }


    format_process("FCFS Scheduling algorithm");

    display_chart(list, size);

    return waiting / size;

}

int main() {

    //test_processes();
    Proc** list = get_processes();

    printf("Average waiting time: %.2f\n", fcfs(list, 4));

    return 0;
}