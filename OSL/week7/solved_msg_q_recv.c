#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
struct message {
    long type;
    char buff[256];
};

typedef struct message MSG;

void recv_msg() {

    MSG msg;

    key_t key = ftok("progfile", 65);
    int msgid = msgget(key, 0666 | IPC_CREAT);

    msgrcv(msgid, &msg, sizeof(msg), 1, 0);

    printf("Data recevied is %s\n", msg.buff);

    msgctl(msgid, IPC_RMID, NULL);

}

int main() {

    recv_msg();

    return 0;
}