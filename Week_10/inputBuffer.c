#define _CRT_SECURE_NO_WARNINGS

/*  -------------------------------------------
	Input Buffer - Formatted/Unformatted Input
	------------------------------------------- */

#include <stdio.h>

void testGetCharSeq(void)
{
	char v;
	printf("Enter values 'AB':");
	v = getchar();   // Prompts for user input
	printf("getchar() -> v:%c\n", v);
	v = getchar();   // Will NOT prompt, since there are values in the buffer (returns B)!
	printf("getchar() -> v:%c\n", v);
	v = getchar();   // Will NOT prompt, since there are values in the buffer (returns \n [newline])!
	printf("getchar() -> v:%c\n", v);

	printf("Notice you were only prompted once?\n");
	printf("The remaining chars were extracted from the input buffer with each call to getchar()\n");
	printf("Even the invisible newline character for the Enter key was captured in the last call!\n\n");

	printf("Try adding one more call to getchar() and see how it will then stop for user input\n");
	printf("since the input buffer is now empty!\n\n");
}

void testScanf(void)
{
	int val;
	char ch;
	
	printf("Enter an int and a char '8B':");
	scanf("%d%c", &val, &ch);   // Prompts for user input; assigns val=8 and ch=B
	
	// Show assigned values:
	printf("val:%d ch:%c\n\n", val, ch);

	// Attempt to prompt for 1st initial:
	printf("Enter your 1st Initial:");
	ch = getchar();             // Will NOT prompt, since there is a value in the buffer (\n [newline])!

	printf("\n");
	printf("oops... why didn't it stop to get my 1st initial?!\n\n");
}

int main(void)
{
	printf("UNFORMATTED input (getchar):\n\n");
	testGetCharSeq();

    printf("\n");
	printf("FORMATTED input (scanf):\n\n");
	testScanf();

	return 0;
}