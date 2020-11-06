#include <stdio.h>
#include <stdlib.h>

int main(){ //valgrind lets us know that we are wrting 224 bytes inside an unallocated block. This because our array needs 100 * 4 bytes (4 = sizeof(int))
    int *array = malloc(100);
    array[100] = 0;
    free(array);
    return 0;
}
