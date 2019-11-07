#ifndef PROCESS_H
#define PROCESS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct proc {

    int pid;
    int priority;

    int arrival;
    int burst;

    int wait;
    int turn;

    int exit_time;

};

typedef struct proc Proc;

int pid = -1;

void set_pid(Proc* process) {

    if(process)
        process->pid = ++pid;
}

Proc* init_process(int arrival, int burst, int priority) {

    Proc* process = (Proc*) malloc(sizeof(Proc));

    process->arrival = arrival;
    process->burst = burst;
    process->priority = priority;

    process->wait = -1;
    process->turn = -1;
    process->exit_time = -1;

    set_pid(process);

    return process;
}

void format_process(char* chart_name) {

    printf("\n%s\n", chart_name);

    printf("pid\tarrl\tprit\tbrst\twait\tturn\n");

}

void display_process(Proc* pr) {

    if(pr) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", pr->pid, pr->arrival, pr->priority, pr->burst, pr->wait, pr->turn);
    }
}

int comp(const void* p1, const void* p2) {
    //printf("%d..", (*(Proc**)p1)->arrival);
    return (*(Proc**)p1)->arrival > (*(Proc**)p2)->arrival;
}

void test_processes() {

    Proc** arr = (Proc**) malloc(sizeof(Proc*) * 3);

    format_process("Initial entry");

    for(int i = 0; i < 3; i++) {
        arr[i] = init_process(7 - i, rand() % 12, 10 - i); // -1 no priority
        display_process(arr[i]);
    }

    qsort(arr, 3, sizeof(arr[0]), comp);

    format_process("\nSorted with arrival");

    for(int i = 0; i < 3; i++)
        display_process(arr[i]);

}

void display_chart(Proc** list, int size) {

    for(int i = 0; i < size; i++)
        display_process(list[i]);
}

Proc** get_processes() {

    Proc** list = (Proc**) malloc(sizeof(Proc*) * 4);

    list[0] = init_process(0, 12, -1);
    list[1] = init_process(3, 6, -1);
    list[2] = init_process(4, 9, -1);
    list[3] = init_process(8, 2, -1);

    return list;
}

#endif