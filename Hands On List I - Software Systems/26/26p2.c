/*

Name: 26p2.c
Author: Aniket Kumar
Decsription: Write a program to execute an executable program.
            a. use some executable program
            b. pass some input to an executable program. (for example execute an executable of $./a.out name)
Date: September 7th, 2025
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    printf("Parent: Executing another program...\n");

    // Execute ./hello with argument "Aniket"
    execl("./hello", "hello", "Aniket", NULL);
    //  ./temp works here
    perror("execl failed");
    return 1;
}

/*
Terminal 1: 
trafalgarlaw@ANIKETKUMAROMEN:~/Software Systems HandsOn I/26$ gcc -o temp 26p1.c
trafalgarlaw@ANIKETKUMAROMEN:~/Software Systems HandsOn I/26$ 

Terminal 2:
trafalgarlaw@ANIKETKUMAROMEN:~/Software Systems HandsOn I/26$ gcc -o temp2 26p2.c
trafalgarlaw@ANIKETKUMAROMEN:~/Software Systems HandsOn I/26$ ./temp2
Parent: Executing another program...
execl failed: No such file or directory

Terminal 1:
trafalgarlaw@ANIKETKUMAROMEN:~/Software Systems HandsOn I/26$ gcc -o temp 26p1.c
trafalgarlaw@ANIKETKUMAROMEN:~/Software Systems HandsOn I/26$ ./temp
Hello, World!

*/