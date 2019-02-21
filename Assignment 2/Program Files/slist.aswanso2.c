/*
Property of Alexander Joseph Swanson Villares
alexanderjswanson@icloud.com | https://github.com/ajswanny
*/


/* Imports */
#include "slist.aswanso2.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


/* Functions */
int insertStudent(StudentListNode **list, int id, char *name) {

    // If the list is empty, make the new node the head.
    if (*list == NULL) {

        StudentListNode *newNode = (StudentListNode *) malloc(sizeof(StudentListNode));
        newNode->id = id;
        strcpy(newNode->name, name);
        newNode->next = NULL;
        *list = newNode;

    } else {

        // Define a new StudentListNode and helper objects.
        StudentListNode *newNode, *temp, *currentNode;
        newNode = (StudentListNode *) malloc(sizeof(StudentListNode));
        newNode->id = id;
        strcpy(newNode->name, name);

        // Define a reference to the StudentNode list.
        currentNode = *list;

        // Check every node in the list
        while (currentNode != NULL) {

            // If there is a node in the list with the same ID as the new node, return 1.
            if (currentNode->id == newNode->id) { return 1; }

            // Add the new node to the beginning of the list if its ID is the least value.
            if (newNode->id < currentNode->id) {

                newNode->next = currentNode;
                *list = newNode;
                break;

            // Add the new node to the end of the list if its ID is the greatest value.
            } else if (currentNode->next == NULL) {

                newNode->next = NULL;
                currentNode->next = newNode;
                break;

            // Add the new node in between its two respective neighbors.
            } else if (currentNode->id < newNode->id && newNode->id < currentNode->next->id) {

                temp = currentNode->next;
                currentNode->next = newNode;
                newNode->next = temp;
                break;

            }

            // Set currentNode to the next node in the list.
            currentNode = currentNode->next;

        }

    }

    return 0;

}

int findStudent(StudentListNode *list, int id, char *name) {

    // Initialize a reference to the list of StudentListNodes.
    StudentListNode *studentListNode = list;

    // Search the entire list for the given ID.
    while (studentListNode != NULL) {

        if (studentListNode->id == id) {

            // Return a reference to the name of the target StudentListNode.
            strcpy(name, studentListNode->name);
            return 0;

        }

        // Search the next node.
        studentListNode = studentListNode->next;

    }

    return 1;

}

int deleteStudent(StudentListNode **list, int id) {

    // Initialize reference to 'list'.
    StudentListNode *studentListNode = *list;

    // Initialize helper object to hold temporary values.
    StudentListNode *temp = (StudentListNode *) malloc(sizeof(StudentListNode));

    // Traverse the entire list...
    while (studentListNode != NULL) {

        // Check if we must delete the first node in the list.
        if (studentListNode == *list) {

            // Delete the first node in the list if it is the target.
            if (studentListNode->id == id) { *list = studentListNode->next; return 0; }

        }

        // Check for target node.
        if (studentListNode->id == id) {

            // Exclude the target node from the list.
            temp->next = studentListNode->next; return 0;

        }

        // Keep track of the current node and the next node.
        temp = studentListNode;
        studentListNode = studentListNode->next;

    }

    // Indicate that no target node was found.
    return 1;

}

int printList(StudentListNode *list) {

    // Initialize a reference to the list.
    StudentListNode *studentListNode = list;

    // Indicate if list is empty.
    if (studentListNode == NULL) { printf("(empty list)\n"); }

    // Print data about every node.
    while (studentListNode != NULL) {
        printf("| %d %s |\n", studentListNode->id, studentListNode->name);
        studentListNode = studentListNode->next;
    }

    return 0;

}


