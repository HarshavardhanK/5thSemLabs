#include <stdio.h>
#include <string.h>

#include <sys/ipc.h>
#include <sys/shm.h>

void send(char* str) {

    key_t key = ftok("shm", 70);
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);

    char* shm_str = (char*) shmat(shmid, (void*) 0, 0);
    strcpy(shm_str, str);

    shmdt(shm_str);
}

int main(int argc, char** argv) {
    
    send(argv[1]);


    return 0;
}