#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

int ulam(unsigned short int a, FILE *file, int max_steps){
    int x = a;
    while(x != 1){
        if(x % 2 == 0){
            x = x / 2;
        }else{
            x = 3 * x + 1;
        }
        max_steps++;
        fprintf(file, "%d ", x);
    }
    return max_steps;
}

int main(){
    clock_t start = clock();
    FILE *file = fopen("ulam.txt", "w");
    int max_steps = 0;
    int max_steps_value = 0;
    int total_steps = 0;

    if (file == NULL){
        printf("Error opening file!\n");
        exit(1);
    }

    unsigned short int test[65535];
    for (int i = 0; i < 65535; i++){
        test[i] = i+1;
    }

    for (int i =0; i < 65535; i++){
        fprintf(file, "Test %d:\n", test[i]);
        int steps = ulam(test[i], file, max_steps);
        fprintf(file, "\n");
        total_steps += steps;

        if(steps >= max_steps){
            max_steps = steps;
            max_steps_value = test[i];
        }
    }

    fclose(file);

    clock_t end = clock();

    double time_taken = ((double)end - start) / CLOCKS_PER_SEC;
    double average_steps = (double)total_steps/65535;

    printf("Time taken (seconds): %lf\n", time_taken);
    printf("largest number of steps found: %d\n", max_steps);
    printf("average of steps: %lf\n", average_steps);
    printf("number that produced the largest number of steps: %d\n", max_steps_value);

    return 0;
}