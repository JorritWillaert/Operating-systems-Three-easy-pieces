#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(){
    int rc = fork();
    if (rc < 0){
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0){
        char *my_args[2];
        my_args[0] = strdup("/bin/ls");
        my_args[1] = NULL;
        execvp(my_args[0], my_args);
        printf("This shouldn't print out\n");
    } else{
        printf("I'm the parent and I'm just printing something.\n");
    }
    return 0;
}
