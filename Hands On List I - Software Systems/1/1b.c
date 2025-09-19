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
#include <unistd.h>

int main() {
    const char *target = "target.txt", *linkname = "hardlink.txt";

    if (link(target, linkname) == -1) {
        perror("link failed");
        exit(1);
    }

    printf("Hard link created: %s -> %s\n", linkname, target);
    return 0;
}


/*
OUTPUT:
trafalgarlaw@ANIKETKUMAROMEN:~/Software Systems HandsOn I/Done/1$ gcc -o t 1b.c
trafalgarlaw@ANIKETKUMAROMEN:~/Software Systems HandsOn I/Done/1$ ./t
Hard link created: hardlink.txt -> target.txt
*/


/*
Shell Command

# creating a target file
echo "Hello" > target.txt
# creating a hard link
ln target.txt hardlink.txt
*/