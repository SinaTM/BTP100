// Preprocessor directive to disable secure warnings, allowing the use of certain functions that are considered 
// unsafe by some compilers (like Microsoft Visual Studio)
#define _CRT_SECURE_NO_WARNINGS

// Include the Standard Input/Output library
#include <stdio.h>

// Define a macro for the filename to be used throughout the code
#define FILE_NAME "example.data"

// Start of the main function
int main(void)
{
	// Declare a FILE pointer and initialize it to NULL
	FILE* fp = NULL;

	// Open the file with the name provided by FILE_NAME in write mode
	fp = fopen(FILE_NAME, "w");

	// Check if the file was successfully opened
	if (fp == NULL)
	{
		// If the file couldn't be opened, print an error message
		printf("Can't open %s\n", FILE_NAME);
	}
	else
	{
		// If the file was successfully opened, close it
		fclose(fp);

		// After closing the file, set the pointer to NULL to prevent potential issues
		fp = NULL;
	}

	// Here, the same operation is performed again, but with a slightly different structure
	// Open the file with the name provided by FILE_NAME in write mode and check if it was opened successfully in the same step
	if ((fp = fopen(FILE_NAME, "w")) != NULL)
	{
		// If the file was successfully opened, close it
		fclose(fp);

		// After closing the file, set the pointer to NULL to prevent potential issues
		fp = NULL;
	}
	else
	{
		// If the file couldn't be opened, print an error message
		printf("Can't open %s\n", FILE_NAME);
	}

	// Return 0 to indicate that the program finished successfully
	return 0;
}
