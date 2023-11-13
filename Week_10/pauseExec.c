#define _CRT_SECURE_NO_WARNINGS

/*  --------------------------------------------------
	Pausing
	- How to clear the input buffer
	- Ensure application pauses for user input
	- Modify buffer clearing to pause the application
	-------------------------------------------------- */

#include <stdio.h>

void clearBuffer(void)
{
	while (getchar() != '\n')
	{
		// do nothing... 
		// Just remove each outstanding character in the input buffer
	}
}

int main(void)
{
	int val = -999;
	char ch = '!', initial = '!';

	printf("Enter an int and a char '8B':");
	scanf("%d%c", &val, &ch);   // Prompts for user input; assigns val=8 and ch=B
	                            // Input buffer contains: "\n" 
	                            // (leftover unassigned character)
	clearBuffer();
	//getchar(); // This will "discard" the \n char left in the buffer

	printf("(Press Enter to Continue)");
	clearBuffer();

	// Show assigned values
	// Proves 8B has been removed from the buffer and assigned to variables
	printf("val:%d ch:%c\n\n", val, ch);

	// Attempt to prompt for 1st initial:
	printf("Enter your 1st Initial:");
	initial = getchar();  // Will NOT prompt, since there is a \n char in the buffer!
	clearBuffer();

	printf("\n");

	// If variable 'initial' has a newline, we know for sure it didn't prompt 
	// for user input!
	if (initial == '\n')
	{
		printf("oops... why didn't it stop to get my 1st initial?!\n\n");
	}
	else
	{
		printf("initial:%c\n", initial);
	}

	return 0;
}