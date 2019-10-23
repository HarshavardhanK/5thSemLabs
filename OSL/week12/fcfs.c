#include <stdio.h>
#include <stdlib.h>

int fcfs(int track[], int size, int init) {

    int move_ = abs(track[0] - init);

    for(int i = 1; i < size; i++) {
        move_ += abs(track[i] - track[i - 1]);
    }

    return move_;
}

int main(int argc, char** argv) {
    int track[] = {98, 183, 37, 122, 14,124, 65, 67};
    int size = sizeof(track) / sizeof(track[0]);

    int move = fcfs(track, size, 53);

    printf("THM: %d\n", move);

    return 0;
}