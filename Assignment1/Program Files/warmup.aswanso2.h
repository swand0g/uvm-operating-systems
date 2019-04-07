//
// Created by Alexander Swanson on 2019-01-23.
// alexanderjswanson@icloud.com
//

#ifndef ASSIGNMENT_1_WARMUP_ASWANSO2_H
#define ASSIGNMENT_1_WARMUP_ASWANSO2_H

#endif //ASSIGNMENT_1_WARMUP_ASWANSO2_H


/**
 * The struct representing a student's recorded     data.
 */
typedef struct {

    char name[32];
    int id;

} StudentData;

/**
 * Calculates the sum from "sum" to "n".
 *
 * @param n
 * @param sum
 */
int calculateSum(int n, int *sum);

/**
 * Creates a new StudentData record.
 */
int createRecord(int id, char *name, StudentData **record);
