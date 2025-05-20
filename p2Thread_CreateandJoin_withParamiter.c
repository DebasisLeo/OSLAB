#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
struct Args
{
    /* data */int a,b;
};

void* sum(void* arg){
struct Args* data=(struct Args*)arg;
int a=data->a;
int b=data->b;
int *res=malloc(sizeof(int));
*res=a+b;
sleep(2);
pthread_exit(res);
}
int main(){
int a,b;
scanf("%d %d",&a,&b);
struct Args data;
data.a=a;
data.b=b;
pthread_t T1;
void* result;
pthread_create(&T1,NULL,sum,(void*)&data);
pthread_join(T1,&result);
printf("this is main\n");
sleep(2);
printf("the sum is %d\n",*(int *)result);

}