#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t rw_mutex;
sem_t mutex;
int readCnt = 0;

void *reader(void *arg)
{
    int id = *(int *)arg;

    sem_wait(&mutex);
    readCnt++;

    if (readCnt == 1)
    {
        sem_wait(&rw_mutex);
    }

    sem_post(&mutex);

    printf("\nR %d is reading",id);

    sem_wait(&mutex);

    readCnt--;

    if (readCnt == 0)
    {
        sem_post(&rw_mutex);
    }

    sem_post(&mutex);
    
    return NULL;
}

void *writer(void *arg){
    int id= *(int *)arg;
    sem_wait(&rw_mutex);
    printf("\nw %d is writing",id);
    sem_post(&rw_mutex);

    return NULL;
}

int main() {
    pthread_t readers[5], writers[5];
    int ids[5];
    sem_init(&rw_mutex, 0, 1);
    sem_init(&mutex, 0, 1);

    for (int i = 0; i < 5; i++) {
        ids[i] = i + 1;
        pthread_create(&readers[i], NULL, reader, &ids[i]);
        pthread_create(&writers[i], NULL, writer, &ids[i]);
    }

    for (int i = 0; i < 5; i++) {
        pthread_join(readers[i], NULL);
        pthread_join(writers[i], NULL);
    }

    sem_destroy(&rw_mutex);
    sem_destroy(&mutex);

    return 0;
}