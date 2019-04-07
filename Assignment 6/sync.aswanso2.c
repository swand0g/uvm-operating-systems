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

void *out_even_with_sem(void *param);
void *out_odd_with_sem(void *param);
void *out_even_with_mutex(void *param);
void *out_odd_with_mutex(void *param);

typedef struct  {
  int num;
  sem_t *sem;
} SemData;

typedef struct {
  int num;
  pthread_mutex_t *mutex;
  pthread_cond_t cond;
} MutexData;

int main() {

    int N = 40;
    pthread_attr_t attr;
    pthread_attr_init(&attr);

    // Semaphores
    printf("---------- Semaphore ----------\n");
    sem_t s;
    SemData sem_data;
    sem_data.num = N;
    sem_data.sem = &s;
    pthread_t tid1, tid2;
    sem_init(&s, 0, 0);

    pthread_create(&tid2, &attr, out_even_with_sem, &sem_data);
    sleep(1);
    pthread_create(&tid1, &attr, out_odd_with_sem, &sem_data);
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);


    // Mutex
    printf("---------- Mutex ----------\n");
    pthread_mutex_t mutex;
    MutexData mutex_data;
    pthread_cond_t mutex_condition = PTHREAD_COND_INITIALIZER;
    pthread_mutexattr_t shared_m;
    pthread_mutexattr_init(&shared_m);
    pthread_mutexattr_setpshared(&shared_m, PTHREAD_PROCESS_SHARED);
    pthread_mutex_init(&mutex, &shared_m);
    mutex_data.num = N;
    mutex_data.mutex = &mutex;
    mutex_data.cond = mutex_condition;
    pthread_t tid3, tid4;

    pthread_create(&tid4, &attr, out_even_with_mutex, &mutex_data);
    sleep(1);
    pthread_create(&tid3, &attr, out_odd_with_mutex, &mutex_data);
    pthread_join(tid3, NULL);
    pthread_join(tid4, NULL);
    pthread_cond_destroy(&mutex_condition);
    pthread_mutex_destroy(&mutex);

    printf("---------- Finished ----------\n");

    return 0;

}

void *out_even_with_sem(void *param) {

  SemData *data = (SemData *) param;
  int n = data->num;
  sem_t *s = (sem_t *) data->sem;

	int i;
	for (i=0; i<=n; ++i) {
      if (i%2 == 0) {
        printf("%d\n", i);
      }
      if (i != n) {
        sem_wait(s);
      }
	}
  pthread_exit(0);

}

void *out_odd_with_sem(void *param) {

  SemData *data = (SemData *) param;
  int n = data->num;
  sem_t *s = (sem_t *) data->sem;

  int i;
  for (i=1; i<=n; ++i) {
      if (i%2 != 0) {
          printf("%d\n", i);
      }
      sem_post(s);
  }
  pthread_exit(0);

}

void *out_even_with_mutex(void *param) {

  MutexData *data = (MutexData *) param;
  int n = data->num;
  pthread_mutex_t *m = (pthread_mutex_t *) data->mutex;

  int i;
  for (i=0; i<=n; ++i) {
    pthread_mutex_lock(m);
    if (i%2 == 0) {
      printf("%d\n", i);
    }
    if (i != n) {
      pthread_cond_wait(&data->cond, m);
      pthread_mutex_unlock(m);
    }
  }
  pthread_exit(0);

}

void *out_odd_with_mutex(void *param) {

  MutexData *data = (MutexData *) param;
  int n = data->num;
  pthread_mutex_t *m = (pthread_mutex_t *) data->mutex;

  int i;
  for (i=1; i<=n; ++i) {
    pthread_mutex_lock(m);
    if (i%2 != 0) {
      printf("%d\n", i);
    }
    pthread_cond_broadcast(&data->cond);
    pthread_mutex_unlock(m);
  }
  pthread_exit(0);

}
