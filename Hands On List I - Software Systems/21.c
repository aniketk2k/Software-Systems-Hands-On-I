/*

Name: 21.c
Author: Aniket Kumar
Decsription: Write a program, call fork and print the parent and child process id.
Date: September 5th, 2025

*/


#include <stdio.h>
#include <unistd.h>   
#include <sys/types.h> 

int main(){
    pid_t pid;
    pid = fork();

    if(pid < 0){
        perror("Fork creation failed");
        return 1;
    }
    else if(pid == 0){
        printf("Child Process:\n");
        printf("\tMy(i.e. child) PID is: %d\n", getpid());
        printf("\tMy Parent's PID is: %d\n", getppid());
    }
    else{
        printf("Parent Process:\n");
        printf("\tMy PID is: %d\n", getpid());
        printf("\tMy Child's PID is: %d\n", pid);
    }

    return 0;
}

/*
trafalgarlaw@ANIKETKUMAROMEN:~/Software Systems HandsOn I$ gcc -o temp 21.c
trafalgarlaw@ANIKETKUMAROMEN:~/Software Systems HandsOn I$ ./temp
Parent Process:
	My PID is: 15618
	My Child's PID is: 15619
Child Process:
	My(i.e. child) PID is: 15619
	My Parent's PID is: 15618
*/