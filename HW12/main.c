#include <stdio.h>

#include "lexicalAnalyzer.c"
#include "lexicalAnalyzerTest.c"

#define MAX_STRING_LENGTH 100

int main()
{
    if (!tests())
    {
        printf("Tests failed");
        return -1;
    }
    printf("Input string:\n");
    char string[MAX_STRING_LENGTH] = { 0 };
    scanf_s("%100s", &string, (unsigned) sizeof(string));
    printf(isNumber(&string[0]) ? "Is number" : "Not a number");
    return 0;
}