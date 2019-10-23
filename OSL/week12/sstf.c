#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int sstf(int track_[], int size, int init) {

    int move_ = 0;

    int track[size + 1];

    track[0] = init;

    for(int i = 0; i < size; i++) {
        track[i + 1] = track_[i];
    }

    for(int i = 0; i < size + 1; i++) {

        int min = INT_MAX;

        for(int j = i + 1; j < size - 1; j++) {

            if(abs(track[i] - track[j]) < min) {
                min = abs(track[i] - track[j]);
                printf("MIN: %d ", min);
            }
        }

        move_ += min;
        printf("MOVe: %d ", move_);
    }

    return move_;
}

int main(int argc, char** argv) {
    int track[] = {98, 183, 37, 122, 14,124, 65, 67};
    int size = sizeof(track) / sizeof(track[0]);

    int move = sstf(track, size, 53);

    printf("THM: %d\n", move);

    return 0;
}