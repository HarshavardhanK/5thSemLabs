#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define FIFO_NAMAE "/tmp/myfifo"

void named_pipe() {

    int fd; 

    printf("Trying to access FIFO");

    if(access(FIFO_NAMAE, F_OK) == -1) {

        int fif_create = mkfifo(FIFO_NAMAE, 0777);
        printf("Accessing fifo");

        if(fif_create == 0) {
            printf("FIFO created successfully\n");

        } else {
            printf("FIFO not created");
        }
    }

    char arr1[80], arr2[80]; 

    fd = open(FIFO_NAMAE, O_WRONLY); 

    printf("Enter str: ");
    fgets(arr2, 80, stdin); 
  
    write(fd, arr2, strlen(arr2)+1); 
    close(fd); 
       
    fd = open(FIFO_NAMAE, O_RDONLY); 

    read(fd, arr1, sizeof(arr1)); 

    printf("User2: %s\n", arr1); 
    close(fd); 
    //while (1) 
    //{ 
        // Open FIFO for write only 
        // fd = open(myfifo, O_WRONLY); 
  
        // // Take an input arr2ing from user. 
        // // 80 is maximum length 
        // printf("Enter str: ");
        // fgets(arr2, 80, stdin); 
  
        // // Write the input arr2ing on FIFO 
        // // and close it 
        // write(fd, arr2, strlen(arr2)+1); 
        // close(fd); 
  
        // // Open FIFO for Read only 
        // fd = open(myfifo, O_RDONLY); 
  
        // // Read from FIFO 
        // read(fd, arr1, sizeof(arr1)); 
  
        // // Print the read message 
        // printf("User2: %s\n", arr1); 
        // close(fd); 
    //} 
}

int main(int argc, char** argv) {
    printf("What");
    named_pipe();

    return 0;
}