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

// ��� ������:
// -1 - �������� ����������� � �������� �����
// -2 - �������� �������� �������� �����
// -3 - �������� ����������� � ���������� �����
Error testBinaryNumber();

#endif //HOMEWORKS1SEMESTER_BINARYNUMBERTEST_H
