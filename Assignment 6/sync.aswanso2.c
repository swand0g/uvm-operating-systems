//
//  sync.aswanso2.c
//  
//
//  Created by Alexander Swanson on 4/1/19.
//

#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *even(void *param);
void *odd(void *param);

int main() {
    
    sem_t sem;
    pthread_attr_t attr;
    pthread_t tid1, tid2;

    pthread_attr_init(&attr);

    pthread_create(&tid2, &attr, even, sem);
    sleep(1);
    pthread_create(&tid1, &attr, odd, NULL);
    
    return 0;
}

void *even(void *param) {

}

void *odd(void *param) {

}
