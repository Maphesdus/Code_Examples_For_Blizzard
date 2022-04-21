// Adam Armstrong
// CS 3060-002 Fall 2020
// Assignment 3 - Multithreaded Program

/* Promise of Originality
I promise that this source code file has, in it's entirety, been
written by myself and by no other person or persons. If at any time an
exact copy of this source code is found to be used by another person in
this term, I understand that both myself and the student that submitted
the copy will receive a zero on this assignment.*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <math.h>

#define NUM_THREADS 10

int primeFactor;
void* getPrimeFactors(void* param);


// MAIN:
int main(int argc, char* argv[]) {
        pthread_t threadIdentifier[argc - 1]; // Thread Identifier
        pthread_attr_t threadAttributes; // Thread Attributes

        for (int i = 1; i < argc; i++){
                // NOTE: malloc = memory allocation
                int* num = malloc(sizeof(*num));

                // NOTE: atoi = A to I (string to integer)
                *num = atoi(argv[i]);

                // Initialize Thread Attributes:
                pthread_attr_init(&threadAttributes);

                //Create Thread:
                pthread_create(&threadIdentifier, &threadAttributes, getPrimeFactors, (void*)num);
        }// END for loop

        for (int i = 1; i < argc; i++){
                void *return_value;

                // Join Threads:
                pthread_join(threadIdentifier, &return_value);
                int* factors = (void*)return_value;

                printf("[%d]\n", i);

                for (int i = 0; i < NUM_THREADS; i ++){
                        if (i == 0)
                                printf("Factors of %d:\n", factors[0]);

                        if (factors[i] != 0 && i > 0)
                                printf("%d\n", factors[i]);
                }// END for loop

        // NO MEMORY LEAKS!!
        free(return_value);

        }// END for loop
}// END MAIN()



// Get Prime Factors:
void* getPrimeFactors(void* param){
        int *num = (void*)param;
        int *factors = (void*)malloc(sizeof(int) * 50);
        factors[0] = *num;
        int count = 1;

        while (*num % 2 == 0){
                *num = *num / 2;
                factors[count] = 2;
                count = count +1;
        }// END while loop

        for (int i = 3; i <= sqrt(*num); i = i + 2){
                while(*num % i == 0){
                        *num = *num / i;
                        factors[count] = i;
                        count = count + 1;
                }// END while loop
        }// END for loop

        if(*num > 2){
                factors[count] = *num;
                count = count + 1;
        }// END if statement

        return (void*)factors;
}// END getPrimeFactors()