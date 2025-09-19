/*

Name: 24.c
Author: Aniket Kumar
Decsription: Write a program to create an orphan process.
Date: September 5th, 2025

*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if(pid < 0){
        perror("fork failed");
        exit(1);
    }
    else if(pid == 0){
        sleep(50); 
        printf("Child process (PID: %d), Parent PID after orphaned: %d\n", getpid(), getppid());
    }
    else{
        printf("Parent process (PID: %d) exiting...\n", getpid());
        exit(0); 
    }

    return 0;
}

/*
trafalgarlaw@ANIKETKUMAROMEN:~/Software Systems HandsOn I$ gcc -o temp 24.c
trafalgarlaw@ANIKETKUMAROMEN:~/Software Systems HandsOn I$ ./temp
Parent process (PID: 15403) exiting...
trafalgarlaw@ANIKETKUMAROMEN:~/Software Systems HandsOn I$ Child process (PID: 15404), Parent PID after orphaned: 2056
*/