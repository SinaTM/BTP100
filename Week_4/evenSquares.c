/* This code prompts the user to enter a number
 and prints the squares of even numbers up to the entered number*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {

    int num, ii;

    printf("Enter a number: ");
    scanf("%d", &num);

    for (ii = 1; ii * ii <= num; ii++) {
        if ((ii * ii) % 2 != 0)
        {
            // do nothing
        }
        else
        {
            printf("%d\n", ii * ii);
        }

    }

    return 0;
}
