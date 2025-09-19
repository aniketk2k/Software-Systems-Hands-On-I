/*

Name: 1a.c
Author: Aniket Kumar
Decsription: Create the following types of a files using (i) shell command (ii) system call
                a. soft link (symlink system call)
                b. hard link (link system call)
                c. FIFO (mkfifo Library Function or mknod system call)
Date: September 4th, 2025

*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main() {
    const char *fifo_name = "myfifo";

    if (mkfifo(fifo_name, 0666) == -1) {
        perror("mkfifo failed");
        exit(1);
    }

    printf("FIFO created: %s\n", fifo_name);
    return 0;
}

/*
OUTPUT:

trafalgarlaw@ANIKETKUMAROMEN:~/Software Systems HandsOn I/Done/1$ gcc -o t 1c.c
trafalgarlaw@ANIKETKUMAROMEN:~/Software Systems HandsOn I/Done/1$ ./t
FIFO created: myfifo

*/




/*
Shell Command:
    # Create a named pipe
    mkfifo myfifo
OR
    mknod myfifo p
*/