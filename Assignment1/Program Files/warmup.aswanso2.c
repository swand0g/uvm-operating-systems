//
// Created by Alexander Swanson on 2019-01-23.
// alexanderjswanson@icloud.com
//

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "warmup.aswanso2.h"


// Calculates the sum from "sum" to "n".
int calculateSum(int n, int *sum) {

    if (n >= 0) {

        // Calculate the sum
        *sum = (n * (n + 1)) / 2;

        return 0;

    } else {

        return 1;

    }

}

// Creates a new StudentData record.
int createRecord(int id, char *name, StudentData **record) {

    if (strlen(name) > 31) {

        // Make pointer point to NULL
        *record = NULL;

        return 1;

    } else {

        StudentData *newRecord;

        // Create memory for new "StudentData" struct
        newRecord = (StudentData *) malloc(sizeof(StudentData));

        // Define new values
        (*newRecord).id = id;
        strcpy((*newRecord).name, name);

        // Define new pointer
        *record = newRecord;

        return 0;

    }

}