#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <math.h>

#define N 8

typedef struct
{
    double *row;
    double *v;
    double result;
} Info;

void *multiply(void *data);

int main() {

    double A[N][N];
    double x[N], y[N], z[N];
    
    int i;
    int j;
    for (i=0; i < N; ++i) {
        for (j = 0; j < N; ++j) {
            A[i][j] = drand48() - 0.5;
        }
    }

    for (i = 0; i < N; ++i) {
        x[i] = drand48() - 0.5;
    }

    Info info[N];
    pthread_t tid[N];
    for (i = 0; i<N; ++i) {
        info[i].row = &A[i][0];
        info[i].v = x;
        pthread_create(&tid[i], NULL, multiply, &info[i]);
    }

    for (i=0; i<N; ++i) {
        pthread_join(tid[i], NULL);
        y[i] = info[i].result;
    }
    
    double sum = 0;
    for (i=0; i<N; ++i) {
        for (j=0; j<N; ++j) {
            sum += A[i][j] * x[j];
        }
        z[i] = sum;
        sum = 0;
    }

    float tolerance = 1e-12;
    for (i=0; i<N; ++i) {
        if (y[i] != z[i]) { printf("FLAG"); }
        else if (fabs(y[i] - z[i]) < tolerance * fabs(y[i])) {
            printf("Level %d: GOOD\n", i);
        }
    }

    return 0;

}

void *multiply(void *data)
{
    Info *info = (Info *)data;
    int i;
    for (i = 0; i < N; ++i)
    {
        info->result += +info->row[i] * info->v[i];
    }

    pthread_exit(0);
}