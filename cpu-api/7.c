#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(){
    int rc = fork();
    if (rc < 0){
        fprintf(stderr, "Failed\n");
        exit(1);
    } else if (rc == 0){ //child
        close(STDOUT_FILENO);
        printf("This is the child.\n"); //Everything printed now won't be be outputted, since the STDOUT has been closed.
        //Extra
        open("new_output.txt", O_CREAT| O_WRONLY);
        printf("Now I'm talking to the new STDOUT.\n");
        //Note: The message "This is the child.\n" was buffered.
    } else{ //parent
        printf("This is the parent speaking.\n");
    }
    return 0;
}
