// Adam Armstrong
// CS 3060-002 Fall 2020
// Assignment 2 - The fork() and exec() System Calls

/* Promise of Originality
I promise that this source code file has, in it's entirety, been
written by myself and by no other person or persons. If at any time an
exact copy of this source code is found to be used by another person in
this term, I understand that both myself and the student that submitted
the copy will receive a zero on this assignment.*/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    printf("fork.c initiated...\n");
    pid_t pid = fork();

    if (pid > 0) {
        printf("Pid %d has started,waiting for child\n", pid);
        int* status = 0;
        wait(status);
        printf("resuming parent.. closing parent\n");
    }

    else if (pid == 0) {
        printf("child process initiated\n");
        if (argc == 1) {
            printf("No arguments provided for: %s\n", argv[0]);
            printf("Terminating child process\n");
        }
        if (argc == 2) {
            printf("One argument provided for: %s\n", argv[0]);
            printf("Executing %s\n", argv[1]);
            execlp(argv[1], argv[1], NULL);
        }
        if (argc > 2) {
            printf("More than one argument provided for: %s\n", argv[0]);
            execvp(argv[1], argv + 1);
        }
    }

    else {
        printf("error\n");
    }

    return 0;
}// END MAIN()