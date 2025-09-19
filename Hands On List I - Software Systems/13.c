/*

Name: 13.c
Author: Aniket Kumar
Decsription: Write a program to wait for a STDIN for 10 seconds using select. 
            Write a proper print statement to verify whether the data is available 
            within 10 seconds or not (check in $man 2 select).
Date: September 7th, 2025
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/select.h>

int main(){
    fd_set set;
    struct timeval timeout;
    int ret;

    FD_ZERO(&set);
    FD_SET(STDIN_FILENO, &set);

    timeout.tv_sec = 10, timeout.tv_usec = 0;

    printf("will wait for i/p for 10sec: \n");
    ret = select(STDIN_FILENO + 1, &set, NULL, NULL, &timeout);

    if(ret == 0)
        printf("No input detected within 10 seconds.\n");
    else if(ret == -1){
        perror("select error");
        exit(EXIT_FAILURE);
    } 
    else{
        char buf[256];
        int n = read(STDIN_FILENO, buf, sizeof(buf)-1);
        if(n > 0){
            buf[n] = '\0';
            printf("Input detected: %s", buf);
        }
    }

    return 0;
}

/*

trafalgarlaw@ANIKETKUMAROMEN:~/Software Systems HandsOn I$ gcc -o temp 13.c
trafalgarlaw@ANIKETKUMAROMEN:~/Software Systems HandsOn I$ ./temp
will wait for i/p for 10sec: 
Aniket 
Input detected: Aniket 
trafalgarlaw@ANIKETKUMAROMEN:~/Software Systems HandsOn I$ ./temp
will wait for i/p for 10sec: 
No input detected within 10 seconds.

*/