#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>

char* formatdate(char* str, time_t val){
        strftime(str, 36, "%d.%m.%Y %H:%M:%S", localtime(&val));
        return str;
}

int main(int argc, char **argv){
    if (argc != 2){
        return 1;
    }
    struct stat buffer;
    if (stat(argv[1], &buffer) < 0){
        return 1;
    }
    printf("Information for %s\n", argv[1]);
    printf("File/directory size: %ld bytes\n", buffer.st_size);
    printf("Inode number: %ld\n", buffer.st_ino);
    printf("User ID of owner: %d\n", buffer.st_uid);
    printf("Group ID of owner: %d\n", buffer.st_gid);
    printf("The number of links that there are to this file/directory: %ld\n", buffer.st_nlink);
    char date[36];
    printf("The last time this file/directory was modified: %s\n", formatdate(date, buffer.st_mtime));
    printf("The current permissions on the file/directory: ");
    printf( (S_ISDIR(buffer.st_mode)) ? "d" : "-");
    printf( (buffer.st_mode & S_IRUSR) ? "r" : "-");
    printf( (buffer.st_mode & S_IWUSR) ? "w" : "-");
    printf( (buffer.st_mode & S_IXUSR) ? "x" : "-");
    printf( (buffer.st_mode & S_IRGRP) ? "r" : "-");
    printf( (buffer.st_mode & S_IWGRP) ? "w" : "-");
    printf( (buffer.st_mode & S_IXGRP) ? "x" : "-");
    printf( (buffer.st_mode & S_IROTH) ? "r" : "-");
    printf( (buffer.st_mode & S_IWOTH) ? "w" : "-");
    printf( (buffer.st_mode & S_IXOTH) ? "x" : "-");
    printf("\n\n");
    return 0;
}
