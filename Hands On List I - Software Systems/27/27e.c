/*

Name: 27.c
Author: Aniket Kumar
Decsription: Write a program to execute ls -Rl by the following system calls
            a. execl
            b. execlp
            c. execled. execv
            e. execvp
Date: September 7th, 2025

*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char *args[] = {"ls", "-Rl", NULL};
    execvp("ls", args);
    perror("execvp failed");
    return 1;
}

/*

trafalgarlaw@ANIKETKUMAROMEN:~/Software Systems HandsOn I/27$ gcc -o temp 27e.c
trafalgarlaw@ANIKETKUMAROMEN:~/Software Systems HandsOn I/27$ ./temp
.:
total 36
-rw-rw-r-- 1 trafalgarlaw trafalgarlaw   991 Sep  7 19:12 27a.c
-rw-rw-r-- 1 trafalgarlaw trafalgarlaw   993 Sep  7 19:12 27b.c
-rw-rw-r-- 1 trafalgarlaw trafalgarlaw  1059 Sep  7 19:12 27c.c
-rw-rw-r-- 1 trafalgarlaw trafalgarlaw   976 Sep  7 19:12 27d.c
-rw-rw-r-- 1 trafalgarlaw trafalgarlaw   421 Sep  7 19:09 27e.c
-rwxrwxr-x 1 trafalgarlaw trafalgarlaw 16056 Sep  7 19:12 temp

*/