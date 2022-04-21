// Adam Armstrong
// September 6th, 2020 (9/6/2020)
// CS 3060-002 Fall 2020
// Assignment #1 - Submitting Your First Program

/* Promise of Originality
I promise that this source code file has, in it's entirety, been
written by myself and by no other person or persons. If at any time an
exact copy of this source code is found to be used by another person in
this term, I understand that both myself and the student that submitted
the copy will receive a zero on this assignment.*/



#include <stdio.h>

int main(int argc, char* argv[]){
	printf("CS 3060: Assignment #1 by Adam Armstrong.\n");

	int j = 0;
	for (int i = 0; i < argc; i++){
		printf("%d: %s\n", i, argv[i]);
		j = i;
	}
	printf("Number of string arguments printed: %d\n\n", j);
	

	return 0;
}// END MAIN()
