/*

Name: 23.c
Author: Aniket Kumar
Decsription: Write a program to create a Zombie state of the running program.
Date: September 6th, 2025

*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    pid_t pid = fork();

    if(pid < 0){
        perror("fork failed");
        exit(1);
    }
    else if(pid == 0){
        printf("Child process (PID: %d) exiting...\n", getpid());
        exit(0);  
    }
    else{
        printf("Parent process (PID: %d) sleeping, child PID: %d\n", getpid(), pid);
        sleep(50);  
        printf("Parent finished sleeping.\n");
    }

    return 0;
}

/*
trafalgarlaw@ANIKETKUMAROMEN:~/Software Systems HandsOn I$ gcc -o temp 23.c
trafalgarlaw@ANIKETKUMAROMEN:~/Software Systems HandsOn I$ ./temp
Parent process (PID: 15428) sleeping, child PID: 15429
Child process (PID: 15429) exiting...
Parent finished sleeping.
*/