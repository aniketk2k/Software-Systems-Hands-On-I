/*

Name: 22.c
Author: Aniket Kumar
Decsription: Write a simple program to execute in an infinite loop at the background. 
            Go to /proc directory and identify all the process related information in the corresponding proc directory.
Date: September 6th, 2025
*/


#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>

int main() {
    int fd = open("output.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);

    pid_t pid = fork();
    if(pid < 0){ 
        perror("fork"); 
        return 1; 
    }

    const char *msg = (pid == 0)  ?  "Child process writes to the file.\n"
                                  :  "Parent process writes to the file.\n";

    write(fd, msg, strlen(msg));
    if(pid > 0) 
        wait(NULL); 
    
    close(fd);
    return 0;
}
            
/*
output file is attached and it will show the following

Parent process writes to the file.
Child process writes to the file.

OR sometimes

Child process writes to the file.
Parent process writes to the file.

*/