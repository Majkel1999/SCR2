#include <stdio.h>
#include <pthread.h>

void *thread_start(void *arg)
{
    pthread_t *thread_ID = arg;
    printf("Hello SCR. Written by thread %lu\n", *thread_ID);
    pthread_exit(NULL);
}

int main()
{
    int err = 0;
    pthread_t ID[10];
    for (int i = 0; i < 10; i++)
    {
        printf("Creating thread %d\n", i + 1);
        err = pthread_create(&ID[i], NULL, thread_start, &ID[i]);
        if (err != 0)
        {
            printf("Error: %d\n", err);
            pthread_exit(NULL);
        }
    }
    pthread_exit(0);
}