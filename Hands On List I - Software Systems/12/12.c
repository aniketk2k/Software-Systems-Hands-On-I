/*

Name: 12.c
Author: Aniket Kumar
Decsription: Write a program to find out the opening mode of a file. Use fcntl.
Date: September 6th, 2025

*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

void dis_fl_mode(int fd) {
    int flags = fcntl(fd, F_GETFL);
    switch(flags  &  O_ACCMODE){
        case O_RDONLY: printf("Opened in READ-ONLY mode\n"); break;
        case O_WRONLY: printf("Opened in WRITE-ONLY mode\n"); break;
        case O_RDWR:   printf("Opened in READ-WRITE mode\n"); break;
    }

    if(flags  &  O_APPEND)   printf("Append mode enabled\n");
    if(flags  &  O_NONBLOCK) printf("Non-blocking mode enabled\n");
    if(flags  &  O_SYNC)     printf("Synchronous I/O enabled\n");
}

int main() {
    int fd = open("example_file.txt", O_RDWR | O_APPEND | O_CREAT, 0644);

    dis_fl_mode(fd);
    close(fd);
    return 0;
}

/*
trafalgarlaw@ANIKETKUMAROMEN:~/Software Systems HandsOn I$ gcc -o temp 12.c
trafalgarlaw@ANIKETKUMAROMEN:~/Software Systems HandsOn I$ ./temp
Opened in READ-WRITE mode
Append mode enabled
*/