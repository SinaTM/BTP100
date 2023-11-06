#define _CRT_SECURE_NO_WARNINGS

// Passing an Array to a Function
// passArray.c

#include <stdio.h>
#define NGRADES 8

// definition of display() ...

// array using []
void display(int g[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", g[i]);
    }
}

int main(void)
{
    int grade[] = { 10,9,10,8,7,9,8,10 };

    display(grade, NGRADES);

    return 0;
}



/*
// array using * (pointer)
void display(int* g, int n)
{
    for (i = 0; i < n; i++)
    {
        printf("%d ", g[i]);
    }
}

*/