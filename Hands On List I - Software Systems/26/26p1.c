/*

Name: 26p1.c
Author: Aniket Kumar
Decsription: Write a program to execute an executable program.
            a. use some executable program
            b. pass some input to an executable program. (for example execute an executable of $./a.out name)
Date: September 7th, 2025
*/


#include <stdio.h>

int main(int argc, char *argv[]) {
    if(argc > 1)
        printf("Hello, %s!\n", argv[1]);
    else
        printf("Hello, World!\n");
    return 0;
}
