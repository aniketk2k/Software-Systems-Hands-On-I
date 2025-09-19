/*

Name: 14.c
Author: Aniket Kumar
Decsription: Write a program to find the type of a file.
            a. Input should be taken from command line.
            b. program should be able to identify any type of a file.
Date: September 6th, 2025

*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    struct stat info;

    if(argc != 2){
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    if(stat(argv[1], &info) < 0){
        perror("stat");
        exit(1);
    }

    printf("File: %s\n", argv[1]);
    printf("Type: ");

    if(S_ISREG(info.st_mode))       printf("Regular file\n");
    else if(S_ISDIR(info.st_mode))  printf("Directory\n");
    else if(S_ISCHR(info.st_mode))  printf("Character device\n");
    else if(S_ISBLK(info.st_mode))  printf("Block device\n");
    else if(S_ISFIFO(info.st_mode)) printf("FIFO (named pipe)\n");
    else if(S_ISLNK(info.st_mode))  printf("Symbolic link\n");
    else if(S_ISSOCK(info.st_mode)) printf("Socket\n");
    else printf("Unknown\n");

    return 0;
}

/*

trafalgarlaw@ANIKETKUMAROMEN:~/Software Systems HandsOn I$ gcc -o temp 14.c
trafalgarlaw@ANIKETKUMAROMEN:~/Software Systems HandsOn I$ ./temp 14.txt
File: 14.txt
Type: Regular file
trafalgarlaw@ANIKETKUMAROMEN:~/Software Systems HandsOn I$ ./temp 14.md
File: 14.md
Type: Regular file

*/