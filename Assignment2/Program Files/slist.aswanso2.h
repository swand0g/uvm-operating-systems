/*
Property of Alexander Joseph Swanson Villares
alexanderjswanson@icloud.com | https://github.com/ajswanny
*/

#ifndef PROGRAM_FILES_SLIST_ASWANSO2_H
#define PROGRAM_FILES_SLIST_ASWANSO2_H

/**
 * A structure representing a student and their metadata.
 */
typedef struct StudentListNodeStruct {
    int id;
    char name[32];
    struct StudentListNodeStruct *next;
} StudentListNode;

/**
 * Inserts a new StudentListNode into the given list of StudentNodes.
 * @param list The list of StudentListNodes.
 * @param id The id for the new StudentListNode.
 * @param name The name for the new StudentListNode.
 * @return If a new StudentListNode is created successfully, 0; else, 1.
 */
int insertStudent(StudentListNode **list, int id, char *name);

/**
 * Searches the given list for a StudentListNode whose ID matches the given ID.
 * @param list The list of StudentListNodes.
 * @param id The ID to search for.
 * @param name The pointer to the name of an identified StudentListNode.
 * @return If a StudentListNode is found, 0; else, 1.
 */
int findStudent(StudentListNode *list, int id, char *name);

/**
 * Deletes a node with the given Id if it is in the list.
 * @param list The list of StudentNodes.
 * @param id The Id of the target node.
 * @return If a target node is found: 0; else, 1.
 */
int deleteStudent(StudentListNode **list, int id);

/**
 * Prints metadata about every node in a list.
 * @param list The list of StudentListNodes.
 * @return 0 indicating successful operation.
 */
int printList(StudentListNode *list);

#endif //PROGRAM_FILES_SLIST_ASWANSO2_H
