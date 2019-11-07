

#include <stdio.h>
#include <stdlib.h>

#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>

int counter = 0;

pthread_mutex_t lock;

void* run(void* args) {

    pthread_mutex_lock(&lock);

    counter++;

    printf("Job %d has started\n", counter);

    for(int i = 0; i < 100000; i++) 
        for(int j = 0; j < 10; j++) 
        ;
        
    printf("Job %d has finished\n", counter);

    pthread_mutex_unlock(&lock);

    return NULL;
                       
} 

void simple_mutex(int count) {

    pthread_mutex_init(&lock, NULL);

    pthread_t threads[count];

    for(int i = 0; i < count; i++)
        pthread_create(&threads[i], NULL, run, NULL);
    
    for(int i = 0; i < count; i++)
        pthread_join(threads[i], NULL);

    pthread_mutex_destroy(&lock);

}

sem_t semaphore;

int sem_thread_count = 0;

void* run_semaphore(void* args) {

    sem_wait(&semaphore);

    sem_thread_count++;

    printf("Thread %d running..\n", sem_thread_count);

    for(int i = 0; i < 100000; i++)
        for(int j = 0; j < 100; j++)
            ;
    
    printf("Thread %d finished\n", sem_thread_count);
    
    sem_post(&semaphore);

    return NULL;
}

void simple_semaphore(int count) {

    pthread_t threads[count];

    sem_init(&semaphore, 0, 1);

    for(int i = 0; i < count; i++)
        pthread_create(&threads[i], NULL, run_semaphore, NULL);
    
    for(int i = 0; i < count; i++)
        pthread_join(threads[i], NULL);

    //sem_destroy(&semaphore);

}

#include <string.h>

struct file_write {
    FILE* fd;
    char* filename;
    char* content;
};

typedef struct file_write FW;

FW* create_file_write(char* mess, char* filename) {

    FW* fw = (FW*) malloc(sizeof(FW));

    fw->content = (char*) malloc(sizeof(char) * 100);
    fw->filename = (char*) malloc(sizeof(char) * 10);

    strcpy(fw->content, mess);
    strcpy(fw->filename, filename);

    return fw;
}

pthread_mutex_t file_mutex;

void* write_to_file(void* args) {

    pthread_mutex_lock(&file_mutex);

    FW* fw = (FW*) args;

    printf("Writing %s to file %s\n", fw->content, fw->filename);

    fw->fd = fopen(fw->filename, "a+"); //for both reading writing, writing appends
    fputs(fw->content, fw->fd);

    fclose(fw->fd);

    printf("Finished %s to file %s\n", fw->content, fw->filename);

    pthread_mutex_unlock(&file_mutex);

    return NULL;

}

void test_file_parallel() {

    pthread_mutex_init(&file_mutex, NULL);

    FW* fw = create_file_write("hello\n", "par.txt");
    FW* fw1 = create_file_write("hi\n", "par.txt");

    pthread_t threads[2];

    pthread_create(&threads[0], NULL, write_to_file, (void*) fw);
    pthread_create(&threads[1], NULL, write_to_file, (void*) fw1);

    pthread_join(threads[0], NULL); pthread_join(threads[1], NULL);
}

int main(int argc, char** argv) {

    //simple_mutex(3);
    //simple_semaphore(5);
    test_file_parallel();

    return 0;
}