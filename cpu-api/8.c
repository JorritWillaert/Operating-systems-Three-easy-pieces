#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>

int main(){
    //With the help of: https://github.com/xxyzz/ostep-hw/blob/master/5/8.c
    int pipefd[2];
    char buf;

    if (pipe(pipefd) == -1){
        perror("pipe");
        exit(1);
    }

    pid_t rc[2];
    rc[0] = fork();
    if (rc[0] < 0){
        fprintf(stderr, "Failed\n");
        exit(1);
    } else if (rc[0] == 0){
        close(pipefd[0]);
        char str[] = "The first child writes: I'm the first child";
        write(pipefd[1], str, strlen(str));
        close(pipefd[1]);
        waitpid(rc[1], NULL, 0);
    } else{
        rc[1] = fork();
        if (rc[1] < 0){
            fprintf(stderr, "Failed\n");
            exit(1);
        } else if (rc[1] == 0){
        close(pipefd[1]);
        while (read(pipefd[0], &buf, 1) > 0){
            write(STDOUT_FILENO, &buf, 1);
        }
        write(STDOUT_FILENO, "\n", 1);
        close(pipefd[0]);
    }
    }
    return 0;
}
