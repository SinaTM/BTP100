#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define SZ 30

int main(void) {

    char str1[SZ] = "abc";
    char str2[SZ] = "def";
    char str3[SZ] = { 0 };
    char ch = 'd';
    char ch2 = 'z';
    char* rest;
    //char *strncat(char *dest, const char *src, size_t n)
    puts("Testing strncat() function:");
    strncat(str1, str2, 0);
    puts(str1);
    strncat(str1, str2, 1);
    puts(str1);
    strncat(str1, str2, 2);
    puts(str1);
    puts("");

    //char *strncpy(char *dest, const char *src, size_t n)
    puts("Testing strncpy() function:");
    puts(str3);
    puts(strncpy(str3, str1, 2));

    //char *strchr(const char *str, int c)
    rest = strchr(str1, ch);
    printf("String after \"%c\" is - \"%s\"\n", ch, rest);
    rest = strchr(str1, ch2);
    printf("String after \"%c\" is - \"%s\"\n", ch2, rest);

    //char *strrchr(const char *str, int c)
    rest = strrchr(str1, ch);
    printf("String after \"%c\" is - \"%s\"\n", ch, rest);



    return 0;
}


