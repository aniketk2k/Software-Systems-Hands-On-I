/*

Name: 10.c
Author: Aniket Kumar
Decsription: Write a program to open a file with read write mode, write 10 bytes, 
            move the file pointer by 10 bytes (use lseek) and write again 10 bytes.
                a. check the return value of lseek
                b. open the file with od and check the empty spaces in between the data.
Date: September 6th, 2025
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    int file;
    char s1[11]  = "HELLO12345", s2[11] = "WORLD67890";   
    off_t pos;

    file = open("myoutput.txt", O_RDWR | O_CREAT, 0644);

    if(write(file, s1, 10) != 10){
        perror("write s1");
        close(file);
        exit(1);
    }
    printf("Wrote first 10 bytes: %s\n", s1);
    
    pos = lseek(file, 10, SEEK_CUR);
    // if(pos == (off_t)-1){
    //     perror("lseek");
    //     close(file);
    //     exit(1);
    // }
    printf("File pointer moved, new offset = %ld\n", (long)pos);

    if(write(file, s2, 10) != 10){
        perror("write secondData");
        close(file);
        exit(1);
    }
    
    printf("Wrote second 10 bytes: %s\n", s2);
    close(file);
    return 0;
}

/*

trafalgarlaw@ANIKETKUMAROMEN:~/Software Systems HandsOn I$ gcc -o temp 10.c
trafalgarlaw@ANIKETKUMAROMEN:~/Software Systems HandsOn I$ ./temp
Wrote first 10 bytes: HELLO12345
File pointer moved, new offset = 20
Wrote second 10 bytes: WORLD67890

*/
