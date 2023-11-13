#define _CRT_SECURE_NO_WARNINGS

/*  --------------------------------------------------
	stdlib Functions
	- abs(), labs(), llabs()
	- rand(), srand()
	-------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h> // <--- Need this to access the absolute and random functions
#include <time.h>	// <--- Need this to access current time (used in random seed)

// Absolute
void absoluteInt(void);
void absoluteLong(void);
void absoluteLongLong(void);

// Random
void random(void);
void showRandomUpToMax(int max);

int main(void)
{
	// Absolute
//	absoluteInt();
//	absoluteLong();
	//absoluteLongLong();

	// Random
	//srand(time(NULL));
	random();
	//showRandomUpToMax(30);

	return 0;
}


void absoluteInt(void)
{
	int val1, val2;
	
	do
	{
		printf("Enter two integer values (0's to exit): ");
		scanf(" %d %d", &val1, &val2);

		printf("The delta between these values is: %d\n\n",
			abs(val2 - val1));


	} while (val1 != 0 && val2 != 0);
}

void absoluteLong(void)
{
	long int val1, val2;

	do
	{
		printf("Enter two long integer values (0's to exit): ");
		scanf(" %ld %ld", &val1, &val2);

		printf("The delta between these values is: %ld\n\n",
			labs(val2 - val1) );

	} while (val1 != 0 && val2 != 0);
}

void absoluteLongLong(void)
{
	long long int val1, val2;

	do
	{
		printf("Enter two long long integer values (0's to exit): ");
		scanf(" %lld %lld", &val1, &val2);

		printf("The delta between these values is: %lld\n\n",
			llabs(val2 - val1) );

	} while (val1 != 0 && val2 != 0);
}

void random(void)
{
	int keepGoing;

	do {
		printf("Random number: %d\n\n", rand());

		printf("Again? (0 to exit):");
		scanf(" %d", &keepGoing);
		printf("\n");

	} while (keepGoing);
}

void showRandomUpToMax(int max)
{
	int keepGoing;
	int rdm, result;

	do
	{
		rdm = rand();
		result = rdm % max;	// modulus will result in a value between 0 and (max-1)
		result++;			// add 1 because we want a number between 1 and max

		printf("Random number between 1 and %d: %d\n", max, result);

		// Simplified (don't need any local variables!)
		//printf("Random number between 1 and %d: %d\n", max, (rand() % max) + 1);

		printf("Again? (0 to quit): ");

		scanf(" %d", &keepGoing);
	} while (keepGoing);
}