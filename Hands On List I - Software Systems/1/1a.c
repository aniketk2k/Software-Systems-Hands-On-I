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
    const char *target = "target.txt", *linkname = "softlink.txt";

    if(symlink(target, linkname) == -1){
        perror("symlink failed");
        exit(1);
    }

    printf("Symbolic link created: %s -> %s\n", linkname, target);
    return 0;
}

/*
OUTPUT:

trafalgarlaw@ANIKETKUMAROMEN:~/Software Systems HandsOn I/Done/1$ gcc -o t 1a.c
trafalgarlaw@ANIKETKUMAROMEN:~/Software Systems HandsOn I/Done/1$ ./t
Symbolic link created: softlink.txt -> target.txt

*/




/*
Shell Command:

# creating a target file
echo "Hello" > target.txt

# creating a symbolic link
ln -s target.txt softlink.txt

*/