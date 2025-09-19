/*

Name: 29.c
Author: Aniket Kumar
Decsription: Write a program to get scheduling policy and modify the scheduling policy 
                (SCHED_FIFO, SCHED_RR).
Date: September 6th, 2025

*/


#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <unistd.h>

int main(){
    pid_t pid = getpid(); 

    int policy = sched_getscheduler(pid);
    if(policy == -1){
        perror("sched_getscheduler");
        exit(EXIT_FAILURE);
    }

    printf("Current scheduling policy: ");
    switch(policy){
        case SCHED_OTHER: printf("SCHED_OTHER (default)\n"); break;
        case SCHED_FIFO:  printf("SCHED_FIFO (real-time FIFO)\n"); break;
        case SCHED_RR:    printf("SCHED_RR (real-time Round-Robin)\n"); break;
        default:          printf("Unknown\n"); break;
    }

    struct sched_param param;
    param.sched_priority = 10;

    if(sched_setscheduler(pid, SCHED_FIFO, &param) == -1){
        perror("sched_setscheduler");
        exit(EXIT_FAILURE);
    }

    printf("Scheduling policy changed to SCHED_FIFO with priority %d\n", param.sched_priority);

    policy = sched_getscheduler(pid);
    printf("New scheduling policy: ");
    switch(policy){
        case SCHED_OTHER: printf("SCHED_OTHER\n"); break;
        case SCHED_FIFO:  printf("SCHED_FIFO\n"); break;
        case SCHED_RR:    printf("SCHED_RR\n"); break;
        default:          printf("Unknown\n"); break;
    }

    return 0;
}

/*

trafalgarlaw@ANIKETKUMAROMEN:~/Software Systems HandsOn I$ gcc -o temp 29.c
trafalgarlaw@ANIKETKUMAROMEN:~/Software Systems HandsOn I$ ./temp
Current scheduling policy: SCHED_OTHER (default)
sched_setscheduler: Operation not permitted
trafalgarlaw@ANIKETKUMAROMEN:~/Software Systems HandsOn I$ sudo ./temp
[sudo] password for trafalgarlaw: 
Current scheduling policy: SCHED_OTHER (default)
Scheduling policy changed to SCHED_FIFO with priority 10
New scheduling policy: SCHED_FIFO

*/