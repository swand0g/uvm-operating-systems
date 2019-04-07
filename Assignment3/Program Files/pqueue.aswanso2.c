//
// Created by Alexander Swanson on 2019-02-21.
//

#include <stdlib.h>
#include <stdio.h>
#include "pqueue.aswanso2.h"

int enqueue(PQueueNode **pqueue, int priority, void *data) {

    PQueueNode *node = *pqueue;
    PQueueNode *temp;
    PQueueNode *newNode = (PQueueNode *) malloc(sizeof(PQueueNode));
    newNode->priority = priority; newNode->data = data;

    if (node == NULL) {

        newNode->next = NULL;
        *pqueue = newNode;

    } else if (priority < node->priority) {

        newNode->next = node;
        *pqueue = newNode;

    } else {

        while (node != NULL) {

            if (node->next == NULL) {

                node->next = newNode;
                newNode->next = NULL;
                break;

            } else if (node->priority == priority) {

                newNode->next = node->next;
                node->next = newNode;
                break;

            } else if (node->priority < priority && node->next->priority > priority) {

                newNode->next = node->next;
                node->next = newNode;
                break;

            }

            node = node->next;

        }

    }

    return 0;

}

void *dequeue(PQueueNode **pqueue) {

    PQueueNode *node = *pqueue;

    if (node == NULL) {

        return NULL;

    } else {

        *pqueue = node->next;
        return node->data;

    }

}

void *peek(PQueueNode *pqueue) {

    PQueueNode *node = pqueue;

    if (node == NULL) {

        return NULL;

    } else {

        return node->data;

    }

}

void printQueue(PQueueNode *pqueue, void (printFunction)(void*)) {

    PQueueNode *node = pqueue;

    while (node != NULL) {

        printFunction(node->data);
        node = node->next;

    }

}

int getMinPriority(PQueueNode *pqueue) {

    PQueueNode *queueHead = pqueue;

    if (queueHead == NULL) { return -1; } else { return queueHead->priority; }

}

int queueLength(PQueueNode *pqueue) {

    PQueueNode *node = pqueue;

    if (node == NULL) { return 0; } else {

        int l = 0;

        while (node != NULL) {

            l++;
            node = node->next;

        }

        return l;

    }

}

void printStudentRecord(void *data) {

    StudentRecord *studentRecord = data;

    printf("name = %s, id = %d\n", studentRecord->name, studentRecord->id);

}