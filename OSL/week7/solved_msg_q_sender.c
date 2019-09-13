#include <unistd.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <stdio.h>

struct message {
    long type;
    char buffer[256];
};

typedef struct message MSG;

void send_msg() {

    MSG msg;

    key_t key = ftok("progfile", 65);
    int msgid;

    msgid = msgget(key, 0666 | IPC_CREAT);

    msg.type = 1;

    printf("write data: ");
    scanf("%s", msg.buffer);

    msgsnd(msgid, &msg, sizeof(msg), 0);

    printf("message sent is: %s\n", msg.buffer);

}


int main() {

    send_msg();
}