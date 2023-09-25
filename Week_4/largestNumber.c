/* This code prompts the user to enter numbers
until they enter zero, and then it determines and prints
the largest number entered*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {

    double largestNum = 0.0;
    double currentNum;

    do {
        printf("Enter a number (zero to exit): \n");
        scanf("%f", &currentNum);

        if (currentNum > largestNum)
            largestNum = currentNum;
    } while (currentNum > 0);

    printf("\nThe largest number entered was %f\n", largestNum);

    return 0;
}