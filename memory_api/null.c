#include <stdio.h>

int main(){
    int *p;
    p = NULL;
    printf("%i", *p); //Segmentation fault when dereferencing our NULL pointer (memory at address = 0 is read only memory)
    return 0;
}
