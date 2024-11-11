#include <stdbool.h>
#include <stdio.h>
#include "BinaryNumberTest.h"

bool isEqualBinNum(bool correctBinNum[LENGTH_BINARY_NUMBER], bool testBinNum[LENGTH_BINARY_NUMBER])
{
    for (int i = 0; i < LENGTH_BINARY_NUMBER; ++i)
    {
        if (testBinNum[i] != correctBinNum[i])
        {
            return false;
        }
    }
    return true;
}

bool testBinaryRepresent()
{
    int number = 12;
    bool binaryNumber[LENGTH_BINARY_NUMBER] = {0};
    bool correctBinaryNumber[LENGTH_BINARY_NUMBER] = {0};
    correctBinaryNumber[LENGTH_BINARY_NUMBER - 3] = 1; // 000100 = 4
    correctBinaryNumber[LENGTH_BINARY_NUMBER - 4] = 1; // 001000 = 8

    binaryRepresent(binaryNumber, number);
    return isEqualBinNum(correctBinaryNumber, binaryNumber);
}

bool testAddBinaryNumbers()
{
    bool binaryNumber1[LENGTH_BINARY_NUMBER] = {0};
    bool binaryNumber2[LENGTH_BINARY_NUMBER] = {0};

    binaryNumber1[LENGTH_BINARY_NUMBER - 3] = 1; // 000100 = 4
    binaryNumber2[LENGTH_BINARY_NUMBER - 3] = 1; // 000100 = 4

    bool result[LENGTH_BINARY_NUMBER] = {0};
    bool correctResult[LENGTH_BINARY_NUMBER] = {0};
    correctResult[LENGTH_BINARY_NUMBER - 4] = 1; // 001000 = 8

    addBinaryNumbers(binaryNumber1, binaryNumber2, result);
    return isEqualBinNum(correctResult, result);
}

bool testConvertFromBinaryToDecimal()
{
    bool binaryNumber[LENGTH_BINARY_NUMBER] = {0};
    binaryNumber[LENGTH_BINARY_NUMBER - 3] = 1; // 000100 = 4
    binaryNumber[LENGTH_BINARY_NUMBER - 4] = 1; // 001000 = 8
    return convertFromBinaryToDecimal(binaryNumber, LENGTH_BINARY_NUMBER) == 12;
}

Error testBinaryNumber()
{
    if (!testBinaryRepresent())
    {
        printf("Ошибка работы функции BinaryRepresentation.\n");
        return IncorrectBinaryForm;
    }

    if (!testAddBinaryNumbers())
    {
        printf("Ошибка работы функции AddBinaryNumbers.\n");
        return IncorrectSumOfBinary;
    }

    if (!testConvertFromBinaryToDecimal())
    {
        printf("Ошибка работы функции ConversionFromBinaryToDecimal.\n");
        return IncorrectDecimalForm;
    }
    return OK;
}