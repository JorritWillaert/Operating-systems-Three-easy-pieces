#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    int x = 100;
    printf("I'm process %d, and the value of x is %d\n", (int) getpid(), x);
    int rc = fork();
    if (rc < 0){
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0){
        x += 5;
        printf("Child (pid = %d): x = %d\n", (int) getpid(), x);
    } else{
        x += 10;
        printf("I'm the parent of %d, my value of x is %d\n", rc, x);
    }
    return 0;
}
