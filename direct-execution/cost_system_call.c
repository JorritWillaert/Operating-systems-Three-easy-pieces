#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
    printf("Experiment 1: precision of 'gettimeofday'.\n");
    int nloops = 1000000;
    struct timeval starting_time;
    struct timeval ending_time;
    gettimeofday(&starting_time, NULL);
    for (int i = 0; i < nloops; i++){
        gettimeofday(&ending_time, NULL);
    }
    gettimeofday(&ending_time, NULL);
    printf("Average time difference in micro seconds: %f\n", (float) (ending_time.tv_sec * 1000000 + ending_time.tv_usec - starting_time.tv_sec * 1000000 - starting_time.tv_usec) / nloops);
    printf("Experiment 2: measure the cost of a system call.\n");
    struct timeval starting_time2;
    struct timeval ending_time2;
    char teststring[0];
    int fd = open("./testfile.txt", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
    int time_1_OK = gettimeofday(&starting_time2, NULL);
    for (int i = 0; i < nloops; i++){
        read(fd, NULL, 0);
    }
    int time_2_OK = gettimeofday(&ending_time2, NULL);
    close(fd);

    printf("Average time difference for system call in micro seconds: %f\n",  (float)(ending_time2.tv_sec * 1000000 + ending_time2.tv_usec - starting_time2.tv_sec * 1000000 - starting_time2.tv_usec) / nloops);
    return 0;
}
