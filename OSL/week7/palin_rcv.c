#include <unistd.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/msg.h>
#include <string.h>

struct mes {
    long int type;
    char buff[1024];
};

typedef struct mes MSG;

int palindrome(char* str) {

    int size = strlen(str);

    for(int i = 0; i < size / 2; i++) {

        if(str[i] != str[size - i - 1]) {
            return 0;
        }
    }

    return 1;
}

void receive() {

    MSG mes;

    key_t key = ftok("palin", 69);
    int msgid = msgget(key, 0666 | IPC_CREAT);

    msgrcv(msgid, &mes, sizeof(mes), 1, 0);

    if(palindrome(mes.buff)) {
        printf("Palindrome\n");
    } else {
        printf("Not a palindrome\n");
    }

}

int main() {
    receive();

    return 0;
}