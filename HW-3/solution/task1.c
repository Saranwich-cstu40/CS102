#include <stdio.h>

int main (){
    int N;
    scanf("%d", &N);
    float values[20];
    int i,j ;
    float min = 2147483648;
    float max = -2147483647;
    int min_index = -1;
    int max_index = -1;
    float sum = 0, average = 0;
    for (i = 0; i < N; i++){
        scanf("%f", &values[i]);
        sum += values[i];
        if (values[i] < min){
            min = values[i];
            min_index = i;
        }
        if (values[i] > max){
            max = values[i];
            max_index = i;
        }
    }
    average = sum / N;
    printf("Maximum value: %10.2f\n", max);
    printf("Minimum value: %10.2f\n", min);
    printf("Maximum index: %10d\n", max_index);
    printf("Minimum index: %10d\n", min_index);
    printf("Average: %10.2f\n", average);
    printf("Reverse order: ");
    for (i = N-1 ; i >= 0; i--){
        printf(" %.2f ", values[i]);
    }
    printf("\nAbove average list: ");
    for (i = N-1; i >= 0; i--){
        if (values[i] < average) continue;
        printf(" %.2f", values[i]);
    }
    printf("\nNegative coordinates:");
    for (i = 0; i + 1 < N; i += 1) {
        for (j = i + 1; j < N; j += 1) {
            if (values[i] < 0 && values[j] < 0) {
                printf(" (%.2f, %.2f),", values[i], values[j]);
            }
        }
    }
    return 0;
}
