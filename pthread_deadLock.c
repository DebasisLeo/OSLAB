#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
pthread_mutex_t R1,R2;
void* fun1(void* arg){
printf("T1 is required R1\n");
pthread_mutex_lock(&R1);
printf("T1 is accquired R1 succesfully\n");
sleep(2);
printf("T1 is required R2\n");
pthread_mutex_lock(&R2);
printf("T1 is accquired R2 succesfully\n");
pthread_mutex_unlock(&R1);

}
void *fun2(void* arg){
printf("T2 is required R2\n");
pthread_mutex_lock(&R2);
printf("T2 is accquired R2 succesfully\n");
sleep(2);
printf("T2 is required R1\n");
pthread_mutex_lock(&R1);
printf("T2 is accquired R1 succesfully\n");
pthread_mutex_unlock(&R2);

}
int main(){
    pthread_mutex_init(&R1,NULL);
    pthread_mutex_init(&R2,NULL);
    pthread_t T1,T2;
    pthread_create(&T1,NULL,fun1,NULL);
    pthread_create(&T2,NULL,fun2,NULL);
    pthread_join(T1,NULL);
    pthread_join(T2,NULL);
    printf("main process now....");
}