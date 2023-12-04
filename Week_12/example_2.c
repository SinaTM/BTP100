// Preprocessor directive to disable secure warnings, allowing the use of certain functions 
// that are considered unsafe by some compilers (like Microsoft Visual Studio)
#define _CRT_SECURE_NO_WARNINGS

// Include the Standard Input/Output library and string library
#include <stdio.h>
#include <string.h>

// Define a macro for the maximum size of the student's name
#define SZ 10

// Define a macro for the size of the student data array
#define DATASZ 3

// Define a Student structure to hold student data
struct Student
{
	int id;
	double grade;
	char name[SZ];
};

// Define a function that prints the contents of an array of Student structures
void print_func(const struct Student* studentInfo, int arrSize)
{
	int i;
	for (i = 0; i < arrSize; i++)
	{
		printf("Student id = %d; Student grade = %.2lf; Student name = %s\n",
			studentInfo[i].id, studentInfo[i].grade, studentInfo[i].name);
	}
	puts(""); // prints a new line
}

// Start of the main function
int main(void)
{
	// Initialize an array of Student structures
	struct Student stInfo[DATASZ] = { {123, 85.0, "Mary"}, {234, 79.0, "John"}, {342, 74.0, "Joey"} };

	FILE* fp = NULL;
	const char fileName[] = "students_data.txt";
	int i = 0;
	char ch;

	// Print the initial array of Student data
	print_func(stInfo, DATASZ);

	// Open the file in write mode
	fp = fopen(fileName, "w");

	// If the file was successfully opened
	if (fp != NULL)
	{
		// Write the first Student's data to the file
		fprintf(fp, "%d|%.2lf|%s\n", stInfo[i].id, stInfo[i].grade, stInfo[i].name);
		// Close the file
		fclose(fp);
		// Set the file pointer to NULL to prevent potential issues
		fp = NULL;
	}
	else
	{
		// Print an error message if the file could not be opened
		printf("ERROR!: Could not open the file for writing.\n");
	}

	// Open the file in append mode
	fp = fopen(fileName, "a");

	// If the file was successfully opened
	if (fp != NULL)
	{
		// Write the rest of the Student data to the file
		for (i = 1; i < DATASZ; i++)
		{
			fprintf(fp, "%d|%.2lf|%s\n", stInfo[i].id, stInfo[i].grade, stInfo[i].name);
		}
		// Close the file
		fclose(fp);
		// Set the file pointer to NULL to prevent potential issues
		fp = NULL;
	}
	else
	{
		// Print an error message if the file could not be opened
		printf("ERROR!: Could not open the file for appending.\n");
	}

	// Return 0 to indicate that the program finished successfully
	return 0;

}
