/* The code you provided demonstrates the use of different format specifiers in printf() to display the values of variables a, b, and c in various formats */
#define _CRT_SECURE_NO_WARNINGS

//Include: The code includes the necessary header file stdio.h for standard input/output operations
#include <stdio.h>

//Main Function: The main() function serves as the entry point of the program.
int main(void)
{
	// Variable Declarations: three double variables: a, b, and c are declared. These variables are initialized with specific values.

	double a = 4.3253, b = 2.3e-3, c = 91000000.0;

	// Using printf() to display the values of 'a', 'b', and 'c' with different format specifiers:

	// Printing varibles using '%lf' format specifier for 'double' values
	printf("a=%lf\tb=%lf\tc=%lf\n", a, b, c);
	// Use '%7.2f' to display 'a with a width of 7 characters and precision of 2 decimal places, '%0.3e' to display 'b' in scientific notation with 3 decimal places, and '%3lg' to display 'c' in either decimal or scientific notation with 3 significant figures
	printf("a=%7.2f\tb=%0.3e\tc=%0.3lg\n", a, b, c);
	// print variables in scientific notation 
	printf("a=%le\tb=%le\tc=%le\n", a, b, c);
	// print variables in either decimal or scientific notation, whichever is more compact
	printf("a=%lg\tb=%lg\tc=%lg\n", a, b, c);

	return 0;

}