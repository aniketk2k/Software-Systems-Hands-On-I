/*

Name: 30.c
Author: Aniket Kumar
Decsription: Write a program to run a script at a specific time using a Daemon process.
Date: September 7th, 2025

*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

int main(){
    pid_t pid, sid;
    int fd;

    pid = fork();
    if(pid < 0){
        perror("Failed to create child process");
        exit(1);
    }
    if(pid > 0){
        printf("Parent exiting. Child PID: %d\n", pid);
        exit(0);
    }

    sid = setsid();
    if(sid < 0)
        exit(1);

    umask(0);   
    chdir("/home/trafalgarlaw/Software Systems HandsOn I");    

    close(0);
    close(1);
    close(2);

    fd = open("test.txt", O_WRONLY | O_CREAT | O_APPEND, 0644); 
    if(fd < 0)
        exit(1);

    const char *script = "./script.sh"; 
    int target_hour = 14, target_min = 30; 

    while(1){
        time_t now = time(NULL);
        struct tm *t = localtime(&now);
        if(t->tm_hour == target_hour  &&  t->tm_min == target_min){
            system(script); 
            write(fd, "Script executed\n", 16); 
            sleep(60); 
        }
        sleep(10); 
    }

    close(fd);
    return 0;
}

/*

trafalgarlaw@ANIKETKUMAROMEN:~/Software Systems HandsOn I$ gcc -o temp 30.c
trafalgarlaw@ANIKETKUMAROMEN:~/Software Systems HandsOn I$ ./temp
Parent exiting. Child PID: 19710

*/