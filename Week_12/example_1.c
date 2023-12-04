// Preprocessor directive to disable secure warnings, this allows use of functions like fopen, strcpy, etc. 
// which are considered unsafe by the Microsoft Visual Studio Compiler
#define _CRT_SECURE_NO_WARNINGS
// Include the Standard Input/Output library in C
#include <stdio.h>

// Define a constant SZ with value 30. It's not used in this code but could be useful for 
// declaring arrays or buffer sizes if needed
#define SZ 30


// Start of the main function
int main(void)
{
	// Declare a pointer to a FILE type (file pointer) and initialize it to NULL
	FILE* fp = NULL;

	// Define a constant character array (string) for the file name we'll use
	const char fileName[] = "myfile.txt";

	// Open the file with the name provided by fileName in write mode ('w')
	fp = fopen(fileName, "w");

	// Check if the file was successfully opened
	if (fp == NULL)
	{
		// If the file could not be opened, print an error message
		printf("Failed to open the file!");
	}
	else
	{
		// If the file was successfully opened, we can safely close it
		fclose(fp);

		// Set the file pointer to NULL after closing to prevent any possible issues 
		// (like a dangling pointer) that might occur if we tried to use it after the file was closed
		fp = NULL;
	}

	// Return 0 to indicate that the program finished successfully
	return 0;

}
