/*

Name: 3.c
Author: Aniket Kumar
Decsription: Write a program to create a file and print the file descriptor value. 
            Use creat ( ) system call
Date: September 6th, 2025
*/


#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int fd;
    fd = creat("myfile.txt", 0644);
    if(fd < 0){
        perror("File creation failed");
        exit(1);
    }

    printf("File created successfully!\n");
    printf("File descriptor value: %d\n", fd);

    close(fd);  
    return 0;
}

/*
Output: 

trafalgarlaw@ANIKETKUMAROMEN:~/Software Systems HandsOn I$ gcc -o temp 3.c
trafalgarlaw@ANIKETKUMAROMEN:~/Software Systems HandsOn I$ ./temp
File created successfully!
File descriptor value: 3

*/