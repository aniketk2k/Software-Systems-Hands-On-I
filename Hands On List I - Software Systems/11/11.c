/*

Name: 11.c
Author: Aniket Kumar
Decsription: Write a program to open a file, duplicate the file descriptor and 
            append the file with both the descriptors and check whether the file is updated properly or not.
                a. use dup
                b. use dup2
                c. use fcntl
Date: September 7th, 2025

*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define FILE_PATH "test_file.txt"

int main() {
    int fd, fd_dup, fd_dup2, fd_fcntl;
    const char *msgs[] = {
        "Message written by original descriptor.\n",
        "Message written by dup descriptor.\n",
        "Message written by dup2 descriptor.\n",
        "Message written by fcntl descriptor.\n"
    };

    fd = open(FILE_PATH, O_WRONLY | O_APPEND | O_CREAT, 0644);

    fd_dup   = dup(fd);     //lowest available fd
    fd_dup2  = dup2(fd, fd_dup + 1);    // target fd
    fd_fcntl = fcntl(fd, F_DUPFD, fd_dup2 + 1);

    write(fd,       msgs[0], strlen(msgs[0]));
    write(fd_dup,   msgs[1], strlen(msgs[1]));
    write(fd_dup2,  msgs[2], strlen(msgs[2]));
    write(fd_fcntl, msgs[3], strlen(msgs[3]));

    close(fd); close(fd_dup); close(fd_dup2); close(fd_fcntl);

    printf("\n--- File contents ---\n");
    int fd_read = open(FILE_PATH, O_RDONLY);
    char buf[256]; ssize_t n;
    while ((n = read(fd_read, buf, sizeof(buf))) > 0)
        write(STDOUT_FILENO, buf, n);
    close(fd_read);

    return 0;
}

/*

trafalgarlaw@ANIKETKUMAROMEN:~/Software Systems HandsOn I$ gcc -o temp 11.c
trafalgarlaw@ANIKETKUMAROMEN:~/Software Systems HandsOn I$ ./temp

--- File contents ---
Message written by original descriptor.
Message written by dup descriptor.
Message written by dup2 descriptor.
Message written by fcntl descriptor.

*/