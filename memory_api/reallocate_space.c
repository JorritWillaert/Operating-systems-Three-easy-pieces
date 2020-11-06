#include <stdio.h>
#include <stdlib.h>

int main(){ //valgrind: 44 bytes allocated --> (5 + 6) * 4
    int *vector_length_5 = malloc(5 * sizeof(int));
    for (int i = 0; i < 5; i++){
        vector_length_5[i] = i;
    }
    //We want to add a sixth element.
    int *vector_length_6 = realloc(vector_length_5, 6 * sizeof(int));
    free(vector_length_6); //Note: vector_length_5 was automatically made free after realloc
    return 0;
}
