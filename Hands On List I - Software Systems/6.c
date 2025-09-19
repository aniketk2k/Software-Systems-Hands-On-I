/*

Name: 6.c
Author: Aniket Kumar
Decsription: Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls
Date: September 6th, 2025
*/


#include <unistd.h>
#include <stdlib.h>

int main(){
    char buffer[100];
    ssize_t bytes;

    bytes = read(0, buffer, sizeof(buffer));
    if(bytes < 0){
        write(2, "Read error\n", 11); 
        exit(1);
    }

    if(write(1, buffer, bytes) < 0){
        write(2, "Write error\n", 12);
        exit(1);
    }

    return 0;
}

/*
Output:

trafalgarlaw@ANIKETKUMAROMEN:~/Software Systems HandsOn I$ gcc -o temp 6.c
trafalgarlaw@ANIKETKUMAROMEN:~/Software Systems HandsOn I$ ./temp
Hey 
Hey 

*/
