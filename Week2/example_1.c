/* This preprocessor directive is include to disable any warning related to the use of scanf() in Visual Studio */
#define _CRT_SECURE_NO_WARNINGS

// header file to use standard input/output
#include <stdio.h>

int main(void)
{

	// declaring integer variables i1, i2 and i3:
	int i1, i2, i3;
	// declaring double variables d1, d2 and d3:
	double d1, d2, d3;
	// initializing character variable:
	char ch1 = 'L';

	// prompting the user to enter a fraction:
	printf("Please enter a fraction: ");
	// storing the fraction in d1:
	scanf("%lf", &d1);
	/* Print the updated value of d1 with two decimal
	   places and move to the next line.*/
	printf("d1 = %0.2lf\n", d1);
	// Print the value of d1 with four decimal places and move to the next line
	printf("d1 = %0.4lf\n", d1);

	// Round the value of d1 to two decimal places using an integer variable i1 (casting) and store the rounded fraction in d2.
	i1 = (int)((d1 + 0.005) * 100);
	d2 = i1 / 100.0;
	printf("d2 = %lf\n", d2);

	// using the character variable ch1 inside printf()
	printf("ch1 hols %c", ch1);

	return 0;
}
