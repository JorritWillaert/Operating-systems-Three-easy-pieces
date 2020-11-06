#include <stdio.h>
#include <stdlib.h>

int main(){ //The invalid pointer is detected at runtime.
    int *array = malloc(100 * sizeof(int));
    array[33] = 66;
    int *wrong_value = array + 25;
    free(wrong_value);
    printf("Value of element 33 in array: %i\n", array[33]);
    return 0;
}
