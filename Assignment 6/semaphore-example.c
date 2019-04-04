#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *runner(void *param);
void *master(void *param);

main() {
    sem_t sem;
    pthread_attr_t attr;
    pthread_t tid1, tid2;
    
    sem_init(&sem, 0, 0);
    
    pthread_attr_init(&attr);
    
    pthread_create(&tid2, &attr, master, &sem);
    sleep(1);
    pthread_create(&tid1, &attr, runner, &sem);
    
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    
    return(0);
}


void *runner(void *param) {
    sem_t *sem;
    int i;
    int value;
    
    sem = (sem_t *) param;
    
    printf("I am runner: waiting for sem\n");
    sem_wait(sem);
    printf("I am runner: done\n");
    
    pthread_exit(0);
}


void *master(void *param) {
    sem_t *sem;
    int i;
    
    sem = (sem_t *) param;
    
    printf("I am master, sleeping for 5 seconds\n");
    sleep(5);
    printf("I am master: sem_post\n");
    sem_post(sem);
    sleep(1);
    
    pthread_exit(0);
}
