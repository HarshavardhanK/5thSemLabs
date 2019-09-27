#include <stdio.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>

typedef struct {
    long int type;
    char data[1024];
} MSG;

void receive() {
    
    key_t key = ftok("ipc", 10);
    int msgid = msgget(key, 0666 | IPC_CREAT);

    MSG msg;

    msgrcv(msgid, &msg, sizeof(MSG), 1, 0);

    msgctl(msgid, IPC_RMID, NULL);

    printf("Received msg %s\n", msg.data);
}

int main(int argc, char** argv) {

    receive();

    return 0;
}
