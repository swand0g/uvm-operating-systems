#include <stdio.h>
#include <stdlib.h>
#include "warmup.aswanso2.h"


int main() {


    int x = 0;
    int n = 1;

    calculateSum(n, &x);
    printf("%d\n", x);


    int id = 1;
    char *name = "Edsger Dijkstra";
    StudentData *record;

    int rtnval = createRecord(id, name, &record);


    return 0;

}