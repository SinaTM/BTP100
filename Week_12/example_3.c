// Disable secure warnings, usually for using functions considered unsafe by Microsoft Visual Studio Compiler
#define _CRT_SECURE_NO_WARNINGS
// Include the Standard Input/Output library and String library
#include <stdio.h>
#include <string.h>

// Define a macro for the maximum size of the student's name and size of the student data array
#define SZ 10
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
		printf("Student id = %d; Student grade = %.2lf; Student name = %s\n\n",
			studentInfo[i].id, studentInfo[i].grade, studentInfo[i].name);
	}
}

// Start of the main function
int main(void)
{
	// Initialize an array of Student structures with zeros
	struct Student stInfo[DATASZ] = { 0 };

	FILE* fp = NULL;
	const char fileName[] = "students_data.txt";
	int i = 0;
	char ch;

	// Open the file in read mode
	fp = fopen(fileName, "r");

	// If the file was successfully opened
	if (fp != NULL)
	{
		// Read student data from the file until either the end of file is reached or the maximum number of students (DATASZ) has been reached
		while (i < DATASZ && fscanf(fp, "%d|%lf|%10[^\n]%c", &stInfo[i].id, &stInfo[i].grade, stInfo[i].name, &ch) == 4)
		{
			// Print the current student index
			printf("i = %d\n", i);

			// If the last read character was not a newline, then there is leftover data in the current line
			// This could occur if the name was longer than expected (more than SZ characters)
			if (ch != '\n')
			{
				// Discard the remainder of the current line
				while (fgetc(fp) != '\n');
			}

			// Increment the student index
			i++;
		}

		//printf("Is end of the file? %d\n", feof(fp)); 
		//fgetc(fp);
		//rewind(fp);
		//printf("Is end of the file? %d\n", feof(fp));


		// Close the file after reading
		fclose(fp);

		// Set the file pointer to NULL to prevent potential issues
		fp = NULL;
	}
	else
	{
		// Print an error message if the file could not be opened
		printf("ERROR: Unable to open the file!");
	}

	// Print the student data
	print_func(stInfo, DATASZ);

	// Return 0 to indicate that the program finished successfully
	return 0;
}
