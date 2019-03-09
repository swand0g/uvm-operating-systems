//
//  main.c
//  CS201Assignment4
//
//  Created by Alexander Swanson on 3/8/19.
//  Copyright © 2019 aswanso2. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <sys/shm.h>
#include <unistd.h>
#include <sys/wait.h>
#include <ctype.h>

#define BUFFER_SIZE 32

int shmemExample() {

    int pid;
    int memid;
    int key = 35;
    char *ptr;
    char buffer[BUFFER_SIZE];

    strcpy(buffer, "hello from me");

    memid = shmget(key, BUFFER_SIZE, IPC_CREAT | 0666);
    if (memid < 0) {
        printf("shmget() failed\n");
        return(8);
    }

    pid = fork();
    if (pid < 0) {
        printf("fork failed\n");
        return(8);
    }

    if (pid > 0) {
        // this is the parent
        printf("I am the parent, and my pid is %d\n", getpid());

        ptr = (char *) shmat(memid, 0, 0);
        if (ptr == NULL) {
            printf("shmat() failed\n");
            return(8);
        }

        printf("Parent is writing '%s' to the shared memory\n", buffer);
        strcpy(ptr, buffer);
        wait(NULL);

    } else {
        // this is the child
        pid = getpid();
        printf("I am the child, and my pid is %d\n", pid);
        ptr = (char *) shmat(memid, 0, 0);
        if (ptr == NULL) {
            printf("shmat() in child failed\n");
            return(8);
        }

        printf("Child will sleep for two seconds\n");
        sleep(2);
        printf("I am the child, and I read this from the shared memory: '%s'\n", ptr);

        shmdt(ptr);
        return(0);
    }

    shmdt(ptr);
    shmctl(memid, IPC_RMID, NULL);
    return(0);

}

int main(int argc, char *argv[]) {

    char* words[] = {"now", "is", "the", "time", "for", "all", "good", "men"};
    char *ptr;
    char buffer[BUFFER_SIZE];
    int numWords = 8;
    int pid;
    int memId;

    memId = shmget(memId, BUFFER_SIZE, IPC_CREAT | 0666);
    if (memId < 0) { printf("shmget() failed\n"); return(8); }

    pid = fork();
    if (pid < 0) {
        printf("fork failed\n");
        return(8);
    }

    if (pid > 0) {

        // This is the parent.
        printf("I am the parent, and my pid is %d\n", getpid());

        ptr = (char *) shmat(memId, 0, 0);
        if (ptr == NULL) {
            printf("shmat() failed\n");
            return(8);
        }

        int i = 0;
        while (i <numWords) {
            strcpy(ptr, words[i]);
            printf("(P) writing '%s' to shared memory\n", ptr);
            usleep(500000);
            printf("(P) read '%s' from the shared memory\n", ptr);
            i++;
        }

    } else {

        // This is the child.
        pid = getpid();
        printf("I am the child, and my pid is %d\n", pid);

        ptr = (char *) shmat(memId, 0, 0);
        if (ptr == NULL) {
            printf("shmat() in child failed\n");
            return(8);
        }

        int j = 0;
        while (j < numWords) {
            j++;

            printf("(C) read this from shared memory: '%s'\n", ptr);

            // Conversion
            char *p = ptr;
            while (*p) {
                *p = toupper(*p);
                p++;
            }

            printf("(C) write this to the shared memory: '%s'\n", ptr);

            usleep(1000000);

        }

        shmdt(ptr);
        return (0);

    }

    shmdt(ptr);
    shmctl(memId, IPC_RMID, NULL);
    return(0);

    /**
     * Everything in the program seems to work correctly. The interaction between the parent and the child is correct,
     * for the most part. The only anomaly is that the child does not seem to be able to read three words from the list,
     * despite the fact that the parent can read and write them. Although I am unsure, my best guess about the reason
     * for this anomaly is that the operating system is shuffling contents of memory locations as a result of other
     * running programs. I do not believe I would change any of the structure of my program... However, I would conduct
     * more research in order to learn what I could do to force the Operating System to allow me constant access to
     * memory locations I instantiate data in -- if this is indeed the problem.
     */

}
