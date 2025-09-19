/*

Name: 28.c
Author: Aniket Kumar
Decsription: Write a program to get maximum and minimum real time priority.
Date: September 5th, 2025

*/


#include <stdio.h>
#include <unistd.h>
#include <sched.h>
#include <sys/types.h>

int main(){
    int min_fifo = sched_get_priority_min(SCHED_FIFO);
    int max_fifo = sched_get_priority_max(SCHED_FIFO);
    int min_rr = sched_get_priority_min(SCHED_RR);
    int max_rr = sched_get_priority_max(SCHED_RR);

    if(min_fifo == -1  ||  max_fifo == -1  ||  min_rr == -1  ||  max_rr == -1){
        perror("sched_get_priority");
        return -1;
    }

    printf("Real-time Priority Ranges:\n");
    printf("FIFO: min = %d, max = %d\n", min_fifo, max_fifo);
    printf("RR  : min = %d, max = %d\n", min_rr, max_rr);

    printf("The min real time priority = %d\n", sched_get_priority_min(SCHED_OTHER));
    printf("The max real time priority = %d\n", sched_get_priority_max(SCHED_OTHER));

    return 0;
}

/*
trafalgarlaw@ANIKETKUMAROMEN:~/Software Systems HandsOn I$ gcc -o temp 28.c
trafalgarlaw@ANIKETKUMAROMEN:~/Software Systems HandsOn I$ ./temp
Real-time Priority Ranges:
FIFO: min = 1, max = 99
RR  : min = 1, max = 99
The min real time priority =
*/