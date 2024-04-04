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

// Error code:
// -1 - wrong conversion to binary form
// -2 - wrong addition of two binary numbers
// -3 - wrong conversion to decimal form
Error testBinaryNumber();

#endif //HOMEWORKS1SEMESTER_BINARYNUMBERTEST_H
