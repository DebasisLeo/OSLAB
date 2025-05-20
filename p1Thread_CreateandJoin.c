#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
void* sum(void *arg){
int n;
scanf("%d",&n);
for (int i = 0; i < n; i++)
{
    /* code */int a,b;
    scanf("%d %d",&a,&b);
    printf("%d\n",a+b);
    sleep(2);
}
return NULL;
}
int main(){

pthread_t T1;
pthread_create(&T1,NULL,sum,NULL);
pthread_join(T1,NULL);
printf("This is Main program");
int n;
scanf("%d",&n);
for (int i = 0; i < n; i++)
{
    /* code */printf("%d\n",i);
    sleep(3);
}




    return 0;
}