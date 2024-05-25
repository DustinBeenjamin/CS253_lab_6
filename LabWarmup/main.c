#include <stdio.h>
#include <stdlib.h>
#define NUM_WEIGHTS 5
#define MAX_STRING_SIZE 50

int main() {

    float weights[NUM_WEIGHTS];
    float sum, average;
    float max_weight = 0;

    for (int i = 0; i < NUM_WEIGHTS; i++) {
        weights[i] = 0;
        while (weights[i] <= 0) {
            printf("\nEnter weight %d\n", i + 1);
            if (scanf("%f", &weights[i]) != 1) {
                char garbage[MAX_STRING_SIZE];
                printf("That is not a numerical value. Try again.\n");
                scanf("%s", garbage);
            } else {
                sum += weights[i];
                if (weights[i] > max_weight) {
                    max_weight = weights[i];
                }
            }
        }
    }

    printf("\nYou entered: ");
    for (int i = 0; i < NUM_WEIGHTS; i++) {
        printf("%0.2f ", weights[i]);
    }
    printf("\n");
    printf("Total weight: %0.2f\n", sum);
    printf("Average weight: %0.2f\n", sum / NUM_WEIGHTS);
    printf("Max weight: %0.2f\n", max_weight);



}
