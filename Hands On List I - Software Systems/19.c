/*

Name: 19.c
Author: Aniket Kumar
Decsription: Write a program to find out time taken to execute getpid system call. Use time stamp counter.
Date: September 5th, 2025

*/


#include <stdio.h>
#include <stdint.h>
#include <unistd.h>

static __inline__ uint64_t rdtsc(void) {
    unsigned int hi, lo;
    __asm__ __volatile__ ("rdtsc" : "=a"(lo), "=d"(hi));
    return ((uint64_t)hi << 32) | lo;
}

int main() {
    uint64_t low, high;
    pid_t pid;

    low = rdtsc();          
    pid = getpid();           
    high = rdtsc();            

    printf("Process ID: %d\n", pid);
    printf("Cycles taken by getpid(): %llu\n", (unsigned long long)(high-low));

    return 0;
}

/*
trafalgarlaw@ANIKETKUMAROMEN:~/Software Systems HandsOn I$ gcc -o temp 19.c
trafalgarlaw@ANIKETKUMAROMEN:~/Software Systems HandsOn I$ ./temp
Process ID: 15764
Cycles taken by getpid(): 6330
*/