#include "pqueue.aswanso2.h"
#include <memory.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


StudentRecord *createStudent(char *name, int id) {
    StudentRecord *studentRec;
    studentRec = (StudentRecord *) malloc(sizeof(StudentRecord));
    studentRec->id = id;
    strcpy(studentRec->name, name);
    return studentRec;
}

void pqueueTests() {
    int minPriority;
    PQueueNode *pqueue = NULL;
    StudentRecord *studentRec;

    studentRec = createStudent("Chris Paul", 1245);
    enqueue(&pqueue, 5, studentRec);

    studentRec = createStudent("James Harden", 2324);
    enqueue(&pqueue, 3, studentRec);

    studentRec = createStudent("Kevin Love", 3794);
    enqueue(&pqueue, 8, studentRec);

    studentRec = createStudent("Dwyane Wade", 8345);
    enqueue(&pqueue, 7, studentRec);

    studentRec = createStudent("Luol Deng", 3245);
    enqueue(&pqueue, 1, studentRec);

    studentRec = createStudent("Al Horford", 4326);
    enqueue(&pqueue, 1, studentRec);

    studentRec = createStudent("Jayson Tatum", 1287);
    enqueue(&pqueue, 8, studentRec);

    printQueue(pqueue, printStudentRecord);

    printf("--------------------------------------------------\n");
    studentRec = peek(pqueue);
    printf("peek: ");
    printStudentRecord(studentRec);

    studentRec = dequeue(&pqueue);
    printf("dequeued: ");
    printStudentRecord(studentRec);

    studentRec = peek(pqueue);
    printf("peek: ");
    printStudentRecord(studentRec);

    studentRec = dequeue(&pqueue);
    printf("dequeued: ");
    printStudentRecord(studentRec);

    studentRec = peek(pqueue);
    printf("peek: ");
    printStudentRecord(studentRec);

    printf("--------------------------------------------------\n");

    studentRec = createStudent("Donovan Mitchell", 934);
    enqueue(&pqueue, 2, studentRec);

    studentRec = createStudent("Kyle Korver", 7328);
    enqueue(&pqueue, 3, studentRec);

    printQueue(pqueue, printStudentRecord);

    printf("--------------------------------------------------\n");

    while (queueLength(pqueue) > 0) {
        minPriority = getMinPriority(pqueue);
        printf("min priority = %d\n", minPriority);
        studentRec = dequeue(&pqueue);
        printf("dequeued: ");
        printStudentRecord(studentRec);
    }
}

int main() {

    pqueueTests();

    return 0;
}


