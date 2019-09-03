#ifndef PROCESS_H
#define PROCESS_H

#include <stdio.h>
#include <stdlib.h>

int pid = 0;

struct process {

    int burst;
    int arrival;
    int priority;

    unsigned int pid;
};

typedef struct process PROC;

PROC* create_process(int burst, int arrival, int priority) {
    
    PROC* proc = (PROC*) malloc(sizeof(PROC));
    proc->burst = burst;
    proc->arrival = arrival;
    proc->priority = -1;
    proc->pid = pid++;

    return proc;
}

void print_process(PROC* proc) {

    if(proc) {
        printf("PID %d | Arrival %d\n", proc->pid, proc->arrival);
    } else {
        printf("No object\n");
    }
}

#endif