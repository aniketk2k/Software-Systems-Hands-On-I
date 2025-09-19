/*

Name: 7.c
Author: Aniket Kumar
Decsription: Write a program to copy file1 into file2 ($cp file1 file2).
Date: September 6th, 2025

*/


#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define bsize 1024  

int main(int argc, char *argv[]) {
    int src_fd, dest_fd;
    ssize_t n;
    char ds[bsize];

    if(argc != 3){
        fprintf(stderr, "Usage: %s <source> <destination>\n", argv[0]);
        exit(1);
    }

    src_fd = open(argv[1], O_RDONLY);
    dest_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);

    while((n = read(src_fd, ds, bsize)) > 0) 
        if(write(dest_fd, ds, n) != n){
            perror("write");
            close(src_fd);
            close(dest_fd);
            exit(1);
        }

    close(src_fd);
    close(dest_fd);

    printf("File copied successfully from %s to %s\n", argv[1], argv[2]);
    return 0;
}


/*
trafalgarlaw@ANIKETKUMAROMEN:~$ cd Software\ Systems\ HandsOn\ I/Done/7
trafalgarlaw@ANIKETKUMAROMEN:~/Software Systems HandsOn I/Done/7$ code 7.c
trafalgarlaw@ANIKETKUMAROMEN:~/Software Systems HandsOn I/Done/7$ gcc -o temp 7.c
trafalgarlaw@ANIKETKUMAROMEN:~/Software Systems HandsOn I/Done/7$ ./temp 
Usage: ./temp <source> <destination>
trafalgarlaw@ANIKETKUMAROMEN:~/Software Systems HandsOn I/Done/7$ ./temp copy1.txt copy2.txt
File copied successfully from copy1.txt to copy2.txt
*/