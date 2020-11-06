#include <stdio.h>
#include <stdlib.h>

int main(){ //This actually prints (correctly) the value of 66! But, memory is free now, so it could have been overwritten.
            //valgrind tells us that this space was already been made free.
    int *array = malloc(100 * sizeof(int));
    array[33] = 66;
    free(array);
    printf("Value of element 33 in array: %i\n", array[33]);
    return 0;
}
