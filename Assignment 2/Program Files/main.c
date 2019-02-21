//
// Created by Alexander Swanson on 2019-02-07.
//

#include <string.h>
#include <stdlib.h>
#include <printf.h>
#include "slist.aswanso2.h"

int main() {

    StudentListNode *theList = NULL;
    char name[32];
    int number;
    int rc;

    strcpy(name, "Trey Burke");
    rc = insertStudent(&theList, 23, name);
    if (rc == 0)
        printf("inserted %s\n", name);
    else
        printf("failed to insert %s\n", name);

    strcpy(name, "Tim Hardaway Jr.");
    rc = insertStudent(&theList, 3, name);
    if (rc == 0)
        printf("inserted %s\n", name);
    else
        printf("failed to insert %s\n", name);

    strcpy(name, "Emmanuel Mudiay");
    rc = insertStudent(&theList, 1, name);
    if (rc == 0)
        printf("inserted %s\n", name);
    else
        printf("failed to insert %s\n", name);

    strcpy(name, "Lance Thomas");
    rc = insertStudent(&theList, 42, name);
    if (rc == 0)
        printf("inserted %s\n", name);
    else
        printf("failed to insert %s\n", name);

    strcpy(name, "Alonzo Trier");
    rc = insertStudent(&theList, 14, name);
    if (rc == 0)
        printf("inserted %s\n", name);
    else
        printf("failed to insert %s\n", name);

    strcpy(name, "Sterling Brown");
    rc = insertStudent(&theList, 23, name);
    if (rc == 0)
        printf("inserted %s\n", name);
    else
        printf("failed to insert %s\n", name);


    printList(theList);

    printf("==========\n");


    number = 1;
    rc = findStudent(theList, number, name);
    if (rc == 0)
        printf("found student %d: %s\n", number, name);
    else
        printf("did not find student with id = %d\n", number);

    number = 2;
    rc = findStudent(theList, number, name);
    if (rc == 0)
        printf("found student %d: %s\n", number, name);
    else
        printf("did not find student with id = %d\n", number);

    number = 42;
    rc = findStudent(theList, number, name);
    if (rc == 0)
        printf("found student %d: %s\n", number, name);
    else
        printf("did not find student with id = %d\n", number);

    number = 100;
    rc = findStudent(theList, number, name);
    if (rc == 0)
        printf("found student %d: %s\n", number, name);
    else
        printf("did not find student with id = %d\n", number);

    number = 23;
    rc = findStudent(theList, number, name);
    if (rc == 0)
        printf("found student %d: %s\n", number, name);
    else
        printf("did not find student with id = %d\n", number);

    printf("==========\n");

    number = 14;
    rc = deleteStudent(&theList, number);
    if (rc == 0)
        printf("deleted %d\n", number);
    else
        printf("failed to delete %d\n", number);

    number = 1;
    rc = deleteStudent(&theList, number);
    if (rc == 0)
        printf("deleted %d\n", number);
    else
        printf("failed to delete %d\n", number);

    number = 3;
    rc = findStudent(theList, number, name);
    if (rc == 0)
        printf("found student %d: %s\n", number, name);
    else
        printf("did not find student with id = %d\n", number);

    number = 6;
    rc = deleteStudent(&theList, number);
    if (rc == 0)
        printf("deleted %d\n", number);
    else
        printf("failed to delete %d\n", number);

    number = 3;
    rc = deleteStudent(&theList, number);
    if (rc == 0)
        printf("deleted %d\n", number);
    else
        printf("failed to delete %d\n", number);

    number = 42;
    rc = deleteStudent(&theList, number);
    if (rc == 0)
        printf("deleted %d\n", number);
    else
        printf("failed to delete %d\n", number);

    number = 1;
    rc = deleteStudent(&theList, number);
    if (rc == 0)
        printf("deleted %d\n", number);
    else
        printf("failed to delete %d\n", number);

    number = 23;
    rc = deleteStudent(&theList, number);
    if (rc == 0)
        printf("deleted %d\n", number);
    else
        printf("failed to delete %d\n", number);

    number = 1;
    rc = findStudent(theList, number, name);
    if (rc == 0)
        printf("found student %d: %s\n", number, name);
    else
        printf("did not find student with id = %d\n", number);
    printList(theList);

}