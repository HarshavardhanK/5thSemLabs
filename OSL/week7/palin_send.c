#include <unistd.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/msg.h>
#include <string.h>

struct mess {
    long int type;
    char buff[1024];
};

typedef struct mess MSG;

void send(char* mes) {

    MSG msg;// = (MSG*) malloc(sizeof(MSG));

    key_t key = ftok("palin", 69);

    int msgid = msgget(key, 0666 | IPC_CREAT);

    msg.type = 1;
    strcpy(msg.buff, mes);

    msgsnd(msgid, &msg, sizeof(msg), 0);

}

int main(int argc, char** argv) {

    send(argv[1]);

    return 0;
}