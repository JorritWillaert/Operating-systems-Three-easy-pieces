#include <stdio.h>
#include <stdlib.h>

int main(){
    int *p;
    p = malloc(sizeof(int));
    //Forget to free memory.
    //gdb does not notice anything special, valgrind detects that we still use 4 bytes at exit.
    return 0;
}
