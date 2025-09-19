/*

Name: 8.c
Author: Aniket Kumar
Decsription: Write a program to open a file in read only mode, read line by line and display each line as it is read.
            Close the file when end of file is reached.
Date: September 6th, 2025

*/


#include <stdio.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>

void displayFileDetails(const char *path) {
    struct stat file_info;

    if(stat(path, &file_info) == -1){
        perror("stat error");
        return;
    }

    printf("a. Inode number: %lu\n", file_info.st_ino);
    printf("b. Number of hard links: %lu\n", file_info.st_nlink);
    printf("c. User ID (UID): %u\n", file_info.st_uid);
    printf("d. Group ID (GID): %u\n", file_info.st_gid);
    printf("e. Size: %ld bytes\n", file_info.st_size);
    printf("f. Block size: %ld bytes\n", file_info.st_blksize);
    printf("g. Number of blocks: %ld\n", file_info.st_blocks);
    printf("h. Last access time: %s\n", ctime(&file_info.st_atime));
    printf("i. Last modification time: %s\n", ctime(&file_info.st_mtime));
    printf("j. Last status change time: %s\n", ctime(&file_info.st_ctime));
}

int main(int argc, char *argv[]) {
    if(argc != 2){
        fprintf(stderr, "Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    displayFileDetails(argv[1]);
    return 0;
}

/*
trafalgarlaw@ANIKETKUMAROMEN:~/Software Systems HandsOn I$ gcc -o temp 9.c
trafalgarlaw@ANIKETKUMAROMEN:~/Software Systems HandsOn I$ ./temp 9.c
a. Inode number: 2243066
b. Number of hard links: 1
c. User ID (UID): 1000
d. Group ID (GID): 1000
e. Size: 1313 bytes
f. Block size: 4096 bytes
g. Number of blocks: 8
h. Last access time: Sun Sep  7 15:40:45 2025

i. Last modification time: Sun Sep  7 15:40:45 2025

j. Last status change time: Sun Sep  7 15:40:45 2025

trafalgarlaw@ANIKETKUMAROMEN:~/Software Systems HandsOn I$ ./temp 9.txt
a. Inode number: 2238658
b. Number of hard links: 1
c. User ID (UID): 1000
d. Group ID (GID): 1000
e. Size: 33 bytes
f. Block size: 4096 bytes
g. Number of blocks: 8
h. Last access time: Sun Sep  7 15:42:33 2025

i. Last modification time: Sun Sep  7 15:42:33 2025

j. Last status change time: Sun Sep  7 15:42:33 2025

*/