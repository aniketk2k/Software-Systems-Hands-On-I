/*

Name: 20.c
Author: Aniket Kumar
Decsription: Find out the priority of your running program. Modify the priority with nice command.
Date: September 5th, 2025

*/


#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>

int main(){
    int old_priority, new_priority;

    old_priority = getpriority(PRIO_PROCESS, 0);
    printf("Initial nice value: %d\n", old_priority);
    new_priority = nice(5); 
    // OR
    // new_priority = setpriority(PRIO_PROCESS, 0, 10);

    if(new_priority == -1) 
        perror("nice");
    else 
        printf("New priority value after increment: %d\n", new_priority);

    printf("Verified new priority value: %d\n", getpriority(PRIO_PROCESS, 0));
    return 0;
}

/*
trafalgarlaw@ANIKETKUMAROMEN:~/Software Systems HandsOn I$ gcc -o temp 20.c
trafalgarlaw@ANIKETKUMAROMEN:~/Software Systems HandsOn I$ ./temp
Initial nice value: 0
New priority value after increment: 5
Verified new priority value: 5
*/