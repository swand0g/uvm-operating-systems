//
// Created by Alexander Swanson on 2019-02-21.
//

#ifndef PROGRAM_FILES_PQUEUE_ASWANSO2_H
#define PROGRAM_FILES_PQUEUE_ASWANSO2_H


/* Structs */
/**
 * StudentRecord
 */
typedef struct {
    int id;
    char name[32];
} StudentRecord;

/**
 * PriorityQueueNode
 */
typedef struct PQueueStruct {
    int priority;
    void *data;
    struct PQueueStruct *next;
} PQueueNode;


/* Functions */
int enqueue(PQueueNode **pqueue, int priority, void *data);

void *dequeue(PQueueNode **pqueue);

void *peek(PQueueNode *pqueue);

void printQueue(PQueueNode *pqueue, void (printFunction)(void*));

int getMinPriority(PQueueNode *pqueue);

int queueLength(PQueueNode *pqueue);

void printStudentRecord(void *data);


#endif //PROGRAM_FILES_PQUEUE_ASWANSO2_H
