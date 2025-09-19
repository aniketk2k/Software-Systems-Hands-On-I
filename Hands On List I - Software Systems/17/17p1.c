/*

Name: 17p1.c
Author: Aniket Kumar
Decsription: Write a program to simulate online ticket reservation. Implement write lock
                Write a program to open a file, store a ticket number and exit. Write a separate program, to 
                open the file, implement write lock, read the ticket number, increment the number and print 
                the new ticket number then close the file.
Date: September 7th, 2025

*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
    int fd = open("ticket.txt", O_WRONLY | O_CREAT, 0644), ticket = 0;

    struct flock lock;
    lock.l_type = F_WRLCK, lock.l_whence = SEEK_SET, lock.l_start = 0;
    lock.l_len = 0; 
    fcntl(fd, F_SETLKW, &lock);

    write(fd, &ticket, sizeof(ticket)); 

    lock.l_type = F_UNLCK; 
    fcntl(fd, F_SETLK, &lock);

    close(fd);
    printf("Ticket file initialized.\n");
    return 0;
}

/*

trafalgarlaw@ANIKETKUMAROMEN:~/Software Systems HandsOn I/17$ gcc -o t1 17p1.c
trafalgarlaw@ANIKETKUMAROMEN:~/Software Systems HandsOn I/17$ gcc -o t2 17p2.c
trafalgarlaw@ANIKETKUMAROMEN:~/Software Systems HandsOn I/17$ ./t1
Ticket file initialized.
trafalgarlaw@ANIKETKUMAROMEN:~/Software Systems HandsOn I/17$ ./t2
Your ticket number: 1
trafalgarlaw@ANIKETKUMAROMEN:~/Software Systems HandsOn I/17$ ./t2
Your ticket number: 2
trafalgarlaw@ANIKETKUMAROMEN:~/Software Systems HandsOn I/17$ ./t2
Your ticket number: 3

*/