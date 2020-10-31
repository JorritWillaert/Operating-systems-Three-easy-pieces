#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    //This output is deterministic!
    int rc = fork();
    if (rc < 0){
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0){ //child
        printf("hello\n");
    } else{ //parent
        int rc_wait = waitpid(rc, NULL, 0);
        printf("goodbye\n");
    }
    return 0;
}
