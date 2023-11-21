#define _CRT_SECURE_NO_WARNINGS
#include <string.h>

int main(void)
{
	char str1[10], str2[10];

	// str1 = "abc";  /*** WRONG ***/
	//str2 = str1;   /*** WRONG ***/

	char str3[10] = "abd"; 

	// if( str1 == str2 )  /*** WRONG ***/
	/* this statement compares str1 and str2 as pointers!!!, it does not compare
	the contents of the two arrays. Since str1 and str2 have different addresses. the expression str1 == str2 must have the value 0*/


}