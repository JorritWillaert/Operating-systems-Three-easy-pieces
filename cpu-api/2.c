#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(){
    //Yes, they can both access the file descriptor returned by open
    int file = open("testfile.txt", O_CREAT| O_WRONLY | O_TRUNC, S_IRWXU);
    int rc = fork();
    write(file, "First line\n", strlen("First line\n"));
    if (rc < 0 || file < 0){
        fprintf(stderr, "Failed\n");
        exit(1);
    } else if (rc == 0){
        write(file, "This is the parent writing\n", strlen("This is the parent writing\n"));
    } else{
        write(file, "This is the child\n", strlen("This is the child\n"));
    }
    return 0;
}
