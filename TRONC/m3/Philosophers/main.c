#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t print_mutex;

void *thread_function(void *arg)
{
    int id;
    int i;

    id = (long)arg;
    i = 0;
    while (i < 5)
    {
        pthread_mutex_lock(&print_mutex);
        printf("🧵 Thread %d - message %d\n", id, i + 1);
        pthread_mutex_unlock(&print_mutex);
        usleep(100000);
        i++;
    }
    return NULL;
}

int main(void)
{
    pthread_t t0, t1, t2, t3, t4;

    pthread_mutex_init(&print_mutex, NULL);

    pthread_create(&t0, NULL, thread_function, (void *)1);
    pthread_create(&t1, NULL, thread_function, (void *)2);
    pthread_create(&t2, NULL, thread_function, (void *)3);
    pthread_create(&t3, NULL, thread_function, (void *)4);
    pthread_create(&t4, NULL, thread_function, (void *)5);

    pthread_join(t0, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    pthread_join(t4, NULL);

    pthread_mutex_destroy(&print_mutex);
    return 0;
}
