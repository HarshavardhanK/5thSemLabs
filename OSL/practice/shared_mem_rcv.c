#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

void receive() {

    key_t key = ftok("shmfile", 70);
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);

    char *str = (char*) shmat(shmid, (void*) 0, 0);

    printf("Data read from shared memory is %s\n", str);

    shmdt(str);

    shmctl(shmid, IPC_RMID, NULL);
}

int main(int argc, char** argv) {
    receive();

    return 0;
}