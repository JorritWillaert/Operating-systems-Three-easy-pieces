#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char *argv[]){
    //Run 'free -m' before and while running this program (in another tab), you will see that the used space increases by the appropriate MBs.
    if (argc != 2){
        fprintf(stderr, "Not the right amount of arguments.\n");
        return 0;
    }
    printf("Process ID: %d\n", (int) getpid());
    int memory_usage = atoi(argv[1]) * 1024 * 1024; //Convert string to integer first, and scale to make MBs.
    int *arr = malloc(memory_usage);
    int length = (int) (memory_usage / sizeof(int));
    int counter = 0;
    clock_t begin = clock();
    while (1){
        double time_spent = (clock() - begin) / CLOCKS_PER_SEC;
        if (time_spent > 30){ //Run program 10 seconds.
            break;
        }
        for (int i = 0; i < length; i++){
            arr[i] += 1;
        }
    }
    free(arr);
    return 0;
}
