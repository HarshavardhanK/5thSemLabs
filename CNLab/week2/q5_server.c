#include "server.h"

#include <time.h>
#include <string.h>

int send_time(void* buffer, int buffer_size) {

    printf("\nsend_time\n");

    time_t rawtime;
    struct tm *info;
    time( &rawtime );
    info = localtime( &rawtime );

    buffer = (char*) buffer;

    strcpy(buffer, asctime(info));

    printf("\nTime is %s\n", buffer);

    return 0;


}

int main() {

    create_server("127.0.0.1", 3000, 256, CHAR, send_time);

    return 0;
}