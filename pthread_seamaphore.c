#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

sem_t s;
int shared = 1;

void* fun1(void* arg) {
    int x;
    sem_wait(&s);
    x = shared;
    x++;
    printf("fun1: the shared resource is now %d\n", x);
    sleep(2);
    shared = x;
    printf("fun1: the shared resource is now updated to %d\n", shared);
    sem_post(&s);
    return NULL;
}

void* fun2(void* arg) {
    int y;
    sem_wait(&s);
    y = shared;
    y++;
    printf("fun2: the shared resource is now %d\n", y);
    sleep(2);
    shared = y;
    printf("fun2: the shared resource is now updated to %d\n", shared);
    sem_post(&s);
    return NULL;
}

int main() {
    sem_init(&s, 0, 1);

    pthread_t T1, T2;
    pthread_create(&T1, NULL, fun1, NULL);
    pthread_create(&T2, NULL, fun2, NULL);

    pthread_join(T1, NULL);
    pthread_join(T2, NULL);

    printf("Main: the shared resource is now %d\n", shared);

    
    return 0;
}
