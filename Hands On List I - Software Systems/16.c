/*

Name: 16.c
Author: Aniket Kumar
Decsription: Write a program to perform mandatory locking.
            a. Implement write lock
            b. Implement read lock
Date: September 6th, 2025

*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/file.h>

void lock_file(int fd, short lock_type) {
    struct flock fl;
    fl.l_type = lock_type;       
    fl.l_whence = SEEK_SET;    // from where to aly lock    
    fl.l_start = 0;              
    fl.l_len = 0;                
    fl.l_pid = getpid();

    if(fcntl(fd, F_SETLKW, &fl) == -1){ 
        perror("fcntl");
        exit(1);
    }

    if(lock_type != F_WRLCK)
        printf("Read lock acquired on file\n");
    else
        printf("Write lock acquired on file\n");
}

void unlock_file(int fd) {
    struct flock fl;
    fl.l_type = F_UNLCK;
    fl.l_whence = SEEK_SET;
    fl.l_start = fl.l_len = 0;

    if(fcntl(fd, F_SETLKW, &fl) == -1){
        perror("fcntl unlock");
        exit(1);
    }

    printf("Lock released\n");
}

int main() {
    int fd = open("lockfile.txt", O_RDWR | O_CREAT, 0644);
    if(fd < 0){
        perror("open");
        exit(1);
    }

    int choice;
    printf("Enter 1 for write lock, 2 for read lock: ");
    scanf("%d", &choice);

    if(choice != 1)
        lock_file(fd, F_RDLCK);
    else
        lock_file(fd, F_WRLCK);

    printf("Press Enter to release lock...\n");
    getchar(); getchar(); // wait for user
    unlock_file(fd);
    close(fd);
    return 0;
}

/*

trafalgarlaw@ANIKETKUMAROMEN:~/Software Systems HandsOn I$ gcc -o temp 16.c
trafalgarlaw@ANIKETKUMAROMEN:~/Software Systems HandsOn I$ ./temp
Enter 1 for write lock, 2 for read lock: 1
Write lock acquired on file
Press Enter to release lock...
       
Lock released

*/