// This code prints a calendar for a given month 
// This preprocessor directive disables warning messages related
// to unsafe functions like 'scanf'
#define _CRT_SECURE_NO_WARNINGS
// include the standard input/output library
#include <stdio.h>
// The 'main' function is the entry point of the program
int main(void) {

    // 'num' stores the number of days in the month
    // 'day' is initialized to 1 and represents the current day
    // in the calendar
    // 'weekDay' stores the starting day of the week 
    int num, day = 1, weekDay, ii;

    printf("Enter number of days in month: ");
    scanf("%d", &num);
    printf("Enter starting day of the week (1=Mon, 7=Sun): ");
    scanf("%d", &weekDay);

    printf("\n Mo Tu We Th Fr Sa Su\n");

    for (ii = 1; ii <= num + weekDay - 1; ii++) {
        if (ii < weekDay)
        {
            printf("   ");
        }
        else
        {
            printf("%3d", day++);
            if (ii % 7 == 0)
            {
                printf("\n");
            }

        }

    }

    printf("\n");
    return 0;
}