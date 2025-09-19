/*

Name: 25.c
Author: Aniket Kumar
Decsription: Write a program to create three child processes. 
            The parent should wait for a particular child (use waitpid system call).
Date: September 6th, 2025

*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    pid_t pids[4];
    int i;

    for(i=1; i<=3; i++){
        pids[i] = fork();
        if(pids[i] < 0){
            perror("fork");
            exit(1);
        }
        else if(!pids[i]){
            printf("Child %d started with PID %d\n", i, getpid());
            sleep(2); 
            printf("Child %d with PID %d exiting\n", i, getpid());
            exit(0);
        }
    }

    // parent process waiting for a particular child (here child 2)
    pid_t waited_pid = pids[2]; 
    printf("Parent waiting for child with PID %d\n", waited_pid);
    waitpid(waited_pid, NULL, 0);
    printf("Parent: Child with PID %d has finished\n", waited_pid);

    for(i=1; i<=3; i++) 
        if (pids[i] != waited_pid)
            waitpid(pids[i], NULL, 0);

    printf("Parent: All children finished\n");
    return 0;
}


/*
trafalgarlaw@ANIKETKUMAROMEN:~/Software Systems HandsOn I$ gcc -o temp 25.c
trafalgarlaw@ANIKETKUMAROMEN:~/Software Systems HandsOn I$ ./temp
Parent waiting for child with PID 19102
Child 3 started with PID 19103
Child 1 started with PID 19101
Child 2 started with PID 19102
Child 1 with PID 19101 exiting
Child 2 with PID 19102 exiting
Child 3 with PID 19103 exiting
Parent: Child with PID 19102 has finished
Parent: All children finished

*/