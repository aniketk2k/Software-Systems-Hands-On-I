/*

Name: 8.c
Author: Aniket Kumar
Decsription: Write a program to open a file in read only mode, read line by line and display each line as it is read.
            Close the file when end of file is reached.
Date: September 6th, 2025

*/


#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define bsize 1   

int main(int argc, char *argv[]) {
    int fd;
    char ch;
    ssize_t n;

    if(argc != 2){
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    fd = open(argv[1], O_RDONLY);
    printf("Reading file: %s\n\n", argv[1]);

    while((n = read(fd, &ch, bsize)) > 0) 
        write(STDOUT_FILENO, &ch, n);  

    close(fd);
    return 0;
}

/*
trafalgarlaw@ANIKETKUMAROMEN:~/Software Systems HandsOn I$ ./temp myfile.txt
Reading file: myfile.txt

Hey
This is code 8
By Aniket Kumar
*/