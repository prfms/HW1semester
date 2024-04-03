#ifndef HOMEWORKS1SEMESTER_BINARYNUMBERTEST_H
#define HOMEWORKS1SEMESTER_BINARYNUMBERTEST_H
#include "BinaryNumber.h"

typedef enum
{
    OK = 0,
    IncorrectBinaryForm = -1,
    IncorrectSumOfBinary = -2,
    IncorrectDecimalForm = -3,
    TestsFailed = -100
} Error;

// Код ошибки:
// -1 - неверная конвертация в двоичную форму
// -2 - неверное сложение двоичных чисел
// -3 - неверная конвертация в десятичную форму
Error testBinaryNumber();

#endif //HOMEWORKS1SEMESTER_BINARYNUMBERTEST_H
