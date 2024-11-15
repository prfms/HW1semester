﻿#ifndef HOMEWORKS1SEMESTER_LEXICALANALYZER_H
#define HOMEWORKS1SEMESTER_LEXICALANALYZER_H

#include <stdbool.h>

typedef enum
{
    Begin = 0,
    IntegerPart,
    DecimalPoint,
    FractionalPart,
    Exponent,
    ExponentSign,
    ExponentDigits
} State;

// Checks if the string is a record of a real number
bool isNumber(const char* string);

#endif //HOMEWORKS1SEMESTER_LEXICALANALYZER_H
