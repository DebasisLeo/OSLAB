#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h> 

struct ThreadData {
    int* arr;
    int size;
};

void* sum(void *arg) {
    struct ThreadData* data = (struct ThreadData*) arg;
    int* ar = data->arr;
    int size = data->size;
int *res = malloc(sizeof(int));
    *res=0;
   
    for (int i = 0; i < size; i++) {
       *res+=ar[i];
    }

    pthread_exit(res);
}

int main() {
    int t;
   
    scanf("%d",&t);

    int ar[t];
    
    for (int i = 0; i < t; i++) {
        scanf("%d", &ar[i]);
    }

   
    struct ThreadData data;
    data.arr = ar;
    data.size = t;

    pthread_t T1;
    pthread_create(&T1, NULL, sum, (void*)&data);
    void* result;
    pthread_join(T1, &result);

    printf("This is Main program\n");
    printf("The sum is %d",*(int*)result);

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("%d\n", i);
        sleep(3);
    }

    return 0;
}
