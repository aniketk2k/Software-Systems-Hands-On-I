/*

Name: 4.c
Author: Aniket Kumar
Decsription: Write a program to open an existing file with read write mode. Try O_EXCL flag also.
Date: September 6th, 2025
*/


#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main() {
    int fd;

    fd = open("myfile.txt", O_RDWR);
    printf("Opened existing file 'testfile.txt' with FD = %d\n", fd);
    close(fd);

    fd = open("testfile.txt", O_RDWR | O_CREAT | O_EXCL, 0644);
    if(fd == -1) 
        printf("Failed to open with O_CREAT | O_EXCL | O_RDWR: %s\n", strerror(errno));
    else{
        printf("Successfully created file with O_EXCL, FD = %d\n", fd);
        close(fd);
    }

    return 0;
}

/*
Output:

trafalgarlaw@ANIKETKUMAROMEN:~/Software Systems HandsOn I$ gcc -o temp 4.c
trafalgarlaw@ANIKETKUMAROMEN:~/Software Systems HandsOn I$ ./temp
Opened existing file 'testfile.txt' with FD = 3
Failed to open with O_CREAT | O_EXCL | O_RDWR: File exists

*/
