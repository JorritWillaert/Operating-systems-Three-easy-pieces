#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    //This output is non-deterministic. Goodbye may be printed before hello. Will be fixed later with wait()
    int rc = fork();
    if (rc < 0){
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0){ //child
        printf("hello\n");
    } else{ //parent
        printf("goodbye\n");
    }
    return 0;
}
