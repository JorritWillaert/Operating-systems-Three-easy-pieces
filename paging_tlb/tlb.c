#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    if (argc != 3){
        printf("Wrong number of arguments.\n");
        return 0;
    }
    int number_of_pages = atoi(argv[1]);
    int number_of_trials = atoi(argv[2]);
    struct timeval starting_time;
    struct timeval ending_time;
    long PAGESIZE = sysconf(_SC_PAGE_SIZE);
    long jump = PAGESIZE / (long) sizeof(int);
    int *a = (int *)malloc((size_t) number_of_pages * (size_t) PAGESIZE);
    gettimeofday(&starting_time, NULL);
    for (int j = 0; j < number_of_trials; j++){
        for (long i = 0; i < number_of_pages * jump; i += jump){
            a[i] += 1;
        }
    }
    free(a);
    gettimeofday(&ending_time, NULL);
    printf("Average access time = %f ns for %i pages.\n", (float) (ending_time.tv_sec * 1000000 + ending_time.tv_usec - starting_time.tv_sec * 1000000 - starting_time.tv_usec) * 1000 / (number_of_trials * number_of_pages) ,number_of_pages);
    return 0;
}
