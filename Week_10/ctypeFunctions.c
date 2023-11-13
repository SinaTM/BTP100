#define _CRT_SECURE_NO_WARNINGS
/*  --------------------------------------------------
	ctype Functions
	- Manipulator: toupper(), tolower()
	- Analysis: isupper(), islower(), isdigit(),
	            isalpha(), isblank(), isspace()
	-------------------------------------------------- */

#include <stdio.h>
#include <ctype.h> // <--- Need this to access the character minipulator and analysis functions

#define PHRASE_LEN 50

// Manipulators
void showUpper(const char* str)
{
	int i;
	
	printf("Testing toupper() manipulator function\n");
	printf("BEFORE: %s\n", str);
	printf("AFTER : ");

	for (i = 0; str[i] != '\0'; i++)
	{
		putchar(toupper(str[i]));
	}
	printf("\n\n");
}

void showLower(const char* str)
{
	int i;

	printf("Testing tolower() manipulator function\n");
	printf("BEFORE: %s\n", str);
	printf("AFTER : ");

	for (i = 0; str[i] != '\0'; i++)
	{
		putchar(tolower(str[i]));
	}
	printf("\n\n");
}

// Analysis
void countUpper(const char* str)
{
	int i, count = 0;

	printf("Testing isupper() analysis function\n");

	for (i = 0; str[i] != '\0'; i++)
	{
		if (isupper(str[i]))
		{
			count++;
		}
	}

	printf("There are %d uppercase characters.\n\n", count);
}

void countLower(const char* str)
{
	int i, count = 0;

	printf("Testing islower() analysis function\n");

	for (i = 0; str[i] != '\0'; i++)
	{
		if (islower(str[i]))
		{
			count++;
		}
	}

	printf("There are %d lowercase characters.\n\n", count);
}

void countDigit(const char* str)
{
	int i, count = 0;

	printf("Testing isdigit() analysis function\n");

	for (i = 0; str[i] != '\0'; i++)
	{
		if (isdigit(str[i]))
		{
			count++;
		}
	}

	printf("There are %d digits (number value) characters.\n\n", count);
}

void countAlpha(const char* str)
{
	int i, count = 0;

	printf("Testing isalpha() analysis function\n");

	for (i = 0; str[i] != '\0'; i++)
	{
		if (isalpha(str[i]))
		{
			count++;
		}
	}

	printf("There are %d letter value characters.\n\n", count);
}

void countBlank(const char* str)
{
	int i, count = 0;

	printf("Testing isblank() analysis function\n");

	for (i = 0; str[i] != '\0'; i++)
	{
		// ' ' or '\t'
		if (isblank(str[i]))
		{
			count++;
		}
	}

	printf("There are %d blank characters (includes only spaces and tabs).\n\n", count);
}

void countSpace(const char* str)
{
	int i, count = 0;

	printf("Testing isspace() analysis function\n");

	for (i = 0; str[i] != '\0'; i++)
	{
		if (isspace(str[i]))
		{
			count++;
		}
	}

	printf("There are %d space characters (includes all whitespace/blank characters).\n\n", count);
}

int main(void)
{
	char words[PHRASE_LEN + 1] = "IPC 144 is awesome!\n\tSeriously it is!";

	printf("C Type library functions\n");
	printf("Source C string used for all tests:\n");
	printf("%s\n\n", words);

	// manipulators (changes/alters character from/to upper/lower case)
	//showUpper(words);
	//showLower(words);

	// analysis (enquires only, true/false testing)
	//countUpper(words);
	//countLower(words);
	//countDigit(words);
	//countAlpha(words);
	//countBlank(words);
	//countSpace(words);

	return 0;
}