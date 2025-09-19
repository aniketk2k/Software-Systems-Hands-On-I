/*

Name: 5.c
Author: Aniket Kumar
Decsription: Write a program to create five new files with infinite loop. 
            Execute the program in the background and check the file descriptor table at /proc/pid/fd.
Date: September 6th, 2025
*/


#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd[5];
    const char *filenames[5] = {"file1.txt", "file2.txt", "file3.txt", "file4.txt", "file5.txt"};

    for(int i=0; i<5; i++){
        fd[i] = open(filenames[i], O_CREAT | O_RDWR, 0644);
        if(fd[i] == -1){
            perror("open");
            exit(1);
        }
        printf("Opened %s with fd = %d\n", filenames[i], fd[i]);
    }

    while (1) 
        sleep(1); 

    return 0;
}

/*

trafalgarlaw@ANIKETKUMAROMEN:~/Software Systems HandsOn I$ gcc -o temp 5.c
trafalgarlaw@ANIKETKUMAROMEN:~/Software Systems HandsOn I$ ./temp
Opened file1.txt with fd = 3
Opened file2.txt with fd = 4
Opened file3.txt with fd = 5
Opened file4.txt with fd = 6
Opened file5.txt with fd = 7

*/