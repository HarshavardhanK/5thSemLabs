#include <stdio.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>

typedef struct {
    long int type;
    char data[1024];
} MSG;

void send(char* message) {

    key_t key = ftok("ipc", 10);

    int msgid = msgget(key, 0666 | IPC_CREAT);

    MSG msg;
    msg.type = 1;

    strcpy(msg.data, message);

    msgsnd(msgid, &msg, sizeof(msg), 0);
}

int main(int argc, char** argv) {

    if(argc < 2) {
        return 1;
    }

    send(argv[1]);

    return 0;
}