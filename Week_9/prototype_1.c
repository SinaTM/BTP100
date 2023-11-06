#define _CRT_SECURE_NO_WARNINGS
/* Raise an integer to the power of another integer
 * power.c
 */

#include <stdio.h> // Include the standard input/output header for IO functions

 // Function prototype declaration for 'power'
int power(int base, int exponent);

// Main function where the program execution begins
int main(void)
{
    int base, exp, answer; // Declare variables for base, exponent, and answer

    // Prompt the user to enter the base
    printf("Enter base : ");
    scanf("%d", &base); // Read the base from user input

    // Prompt the user to enter the exponent
    printf("Enter exponent : ");
    scanf("%d", &exp); // Read the exponent from user input

    // Call the 'power' function and store the result in 'answer'
    answer = power(base, exp);

    // Display the result
    printf("%d^%d = %d\n", base, exp, answer);

    return 0; // Indicate that the program finished successfully
}

// Define the 'power' function that calculates the power of an integer raised to another integer
int power(int base, int exponent)
{
    int result, i; // Declare variables for the result and the loop counter

    result = 1; // Initialize result to 1 (the identity of multiplication)

    // Loop 'exponent' times to multiply the base to the result
    for (i = 0; i < exponent; i++)
    {
        result = result * base; // Multiply the current result by the base
    }

    return result; // Return the computed power
}
