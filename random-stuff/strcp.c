/*
    How strcpy is used

    syntax
        char* strcpy(char* destination, const char* source);
*/
#include <string.h>
#include <stdio.h>

int main()
{

    char str1[] = "Aloha\n";
    char str2[] = "isagi\n";
    char str3[] = "yagami\n";
    char str5[] = "sakuna\n";

    strcpy(str2, str5);

    printf("str1: %s\n", str1);
    printf("str2: %s\n", str2);
    printf("str3: %s\n", str3);
    printf("str5: %s\n", str5);

    // printf("str1 %s\n str2: %s\n str3 %s\n str5: %s\n", str1, str2, str3, str5);

    // gives weird output incase of longer src string

    return 0;
}