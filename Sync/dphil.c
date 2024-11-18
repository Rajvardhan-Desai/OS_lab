#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define N 5
sem_t chopsticks[N];

void *philosopher(void *arg) {
    int id = *(int *)arg;

    sem_wait(&chopsticks[id]);
    sem_wait(&chopsticks[(id + 1) % N]);

    printf("Philosopher %d is eating\n", id);

    sem_post(&chopsticks[(id + 1) % N]);
    sem_post(&chopsticks[id]);

    printf("Philosopher %d is thinking\n", id);
    return NULL;
}

int main() {
    pthread_t philosophers[N];
    int ids[N];
    for (int i = 0; i < N; i++) {
        sem_init(&chopsticks[i], 0, 1);
        ids[i] = i;
    }

    for (int i = 0; i < N; i++)
        pthread_create(&philosophers[i], NULL, philosopher, &ids[i]);

    for (int i = 0; i < N; i++)
        pthread_join(philosophers[i], NULL);

    for (int i = 0; i < N; i++)
        sem_destroy(&chopsticks[i]);

    return 0;
}
