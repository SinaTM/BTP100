#define _CRT_SECURE_NO_WARNINGS

/*  --------------------------------------------------
	C Strings
	- Introduction to C Strings
	- Declaration and construction
	- Input and output
	-------------------------------------------------- */

#include <stdio.h>

// Size for the C string character arrays (printable character length)
#define STRSIZE 8

// Clear the input buffer of any extra characters
void clearBuffer(void)
{
	while (getchar() != '\n')
	{
		// do nothing
	}
}

// Display a plain character array to the screen
void plainCharArray(const char str[], int arrSize)
{
	int i;

	printf("Display 'CString!' using a plain character array (Really inefficient!)\n");

	// NOTE: We need to know how many characters there are in the character array
	for (i = 0; i < arrSize; i++)
	{
		printf("%c", str[i]);
		// NOTE: OR, we could use unformatted output:
		// putchar(str[i]);
	}
	printf("\n");
}

int main(void)
{
	// Declaring and initializing a plain char array (NOT a C String):
	char str[] = { 'C', 'S', 't', 'r', 'i', 'n', 'g', '!' }; // normal char array (NOT a C String)
	plainCharArray(str, 8); // function to display this word to the screen

	// Declaring and initializing C Strings:
	char str1[] = { 'C', 'S', 't', 'r', 'i', 'n', 'g', '1', '\0' }; // long method
	char str2[] = "CString2";	// auto-sizes to 9 (8 printable chars + null terminator byte)
	char str3[9] = "CString3";  // explicitly sized to 9 (8 printable chars + null terminator byte)
	char str4[STRSIZE + 1] = "CString4"; // Macro sizing + 1 for null terminator byte

	// Declaring and initializing C Strings to a safe empty state:
	char str5[9] = { '\0' }; // Safe empty state (assign null terminator byte)
	char str6[9] = { 0 };    // Same as above, only uses decimal ASCII value
	char str7[STRSIZE + 1] = { 0 }; // Safe empty state (used for user input later)

	// Displaying C Strings:
	printf("Values of strings:\n");
	printf("str1:%s\n", str1);
	printf("str2:%s\n", str2);
	printf("str3:%s\n", str3);
	printf("str4:%s\n", str4);
	printf("str5:%s (empty)\n", str5);
	printf("str6:%s (empty)\n", str6);

	// C String input (standard input from user):
	printf("Enter str7: ");
	scanf("%s", str7);  // Note: No '&' address-of operator required!
	clearBuffer();
	printf("str7:%s\n", str7);

	// Protect/respect char array size:
	printf("Enter str7 (enter > 8 chars):");
	scanf("%8s", str7); // Note: char's > 8th will remain in input buffer!
	clearBuffer();
	printf("str7:%s\n", str7);

	// Part:1 Getting strings with multiple words (spaces in between)
	printf("Enter str7 (enter \"I am\"):");
	scanf("%8s", str7); // Will only assign 'I' (spaces represent another value entry)
	clearBuffer();
	printf("str7:%s\n", str7);

	// Part:2 Getting strings with multiple words (spaces in between)
	printf("Enter str7 (enter \"I am\"):");
	scanf("%8[^\n]", str7); // Note: 's' is implied; Both words are stored
	clearBuffer();
	printf("str7:%s\n", str7);

	return 0;
}