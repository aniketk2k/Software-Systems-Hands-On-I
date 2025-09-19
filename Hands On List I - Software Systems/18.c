/*

Name: 18.c
Author: Aniket Kumar
Decsription: Write a program to perform Record locking.
                a. Implement write lock
                b. Implement read lock
                    Create three records in a file. Whenever you access a particular record, 
                    first lock it then modify/access to avoid race condition.
Date: September 7th, 2025

*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define RECORDS 3

struct database {
    int roll;
    int marks;
} db;


int main() {
    int n, t, fd;
    printf("There are %d records in the file.\nSelect a record to access (1-3): ", RECORDS);
    scanf("%d", &n);
    printf("Choose operation: 1. Read  2. Write (default Read): ");
    scanf("%d", &t);

    // Open file, else create one
    fd = open("record.txt", O_RDWR | O_CREAT, 0644);
    off_t size = lseek(fd, 0, SEEK_END);

    if(size < RECORDS*sizeof(db)){
        lseek(fd, 0, SEEK_SET);
        for(int i=0; i<RECORDS; i++){
            db.roll = 0, db.marks = 0;
            write(fd, &db, sizeof(db));
        }
    }

    struct flock lock;
    lock.l_whence = SEEK_SET;
    lock.l_start = sizeof(db)*(n-1), lock.l_len = sizeof(db);
    lock.l_type = (t == 2)  ?  F_WRLCK : F_RDLCK;

    if(fcntl(fd, F_SETLKW, &lock) == -1){
        perror("Cannot obtain lock");
        close(fd);
        exit(1);
    }

    lseek(fd, sizeof(db)*(n-1), SEEK_SET);
    if(t == 2){ 
        printf("Enter roll number: ");
        scanf("%d", &db.roll);
        printf("Enter marks: ");
        scanf("%d", &db.marks);
        if(write(fd, &db, sizeof(db)) != sizeof(db)) 
            perror("Error writing record");
    } 
    else{ 
        if (read(fd, &db, sizeof(db)) == sizeof(db)) 
            printf("Record %d: Roll = %d, Marks = %d\n", n, db.roll, db.marks);
        else 
            perror("Error reading record");
    }

    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);
    close(fd);

    fd = open("record.txt", O_RDONLY);

    printf("\nAll records:\n");
    for(int i=0; i<RECORDS; i++){
        lseek(fd, sizeof(db)*i, SEEK_SET);
        if(read(fd, &db, sizeof(db)) == sizeof(db)) 
            printf("Record %d: Roll = %d, Marks = %d\n", i+1, db.roll, db.marks);
    }

    close(fd);
    return 0;
}

/*

trafalgarlaw@ANIKETKUMAROMEN:~/Software Systems HandsOn I$ gcc -o temp 18.c
trafalgarlaw@ANIKETKUMAROMEN:~/Software Systems HandsOn I$ ./temp
There are 3 records in the file.
Select a record to access (1-3): 1
Choose operation: 1. Read  2. Write (default Read): 2
Enter roll number: 101
Enter marks: 9

All records:
Record 1: Roll = 101, Marks = 9
Record 2: Roll = 0, Marks = 0
Record 3: Roll = 0, Marks = 0
trafalgarlaw@ANIKETKUMAROMEN:~/Software Systems HandsOn I$ ./temp
There are 3 records in the file.
Select a record to access (1-3): 2
Choose operation: 1. Read  2. Write (default Read): 2
Enter roll number: 102
Enter marks: 10

All records:
Record 1: Roll = 101, Marks = 9
Record 2: Roll = 102, Marks = 10
Record 3: Roll = 0, Marks = 0
trafalgarlaw@ANIKETKUMAROMEN:~/Software Systems HandsOn I$ ./temp
There are 3 records in the file.
Select a record to access (1-3): 1
Choose operation: 1. Read  2. Write (default Read): 1
Record 1: Roll = 101, Marks = 9

All records:
Record 1: Roll = 101, Marks = 9
Record 2: Roll = 102, Marks = 10
Record 3: Roll = 0, Marks = 0

*/