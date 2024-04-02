#include <stdbool.h>
#include <stdio.h>
#include "BinaryNumberTest.h"

bool testBinaryRepresentation()
{
    int number = 12;
    unsigned char binaryNumber[LENGTH_BINARY_NUMBER] = {0};
    unsigned char correctBinaryNumber[LENGTH_BINARY_NUMBER] = {0};
    correctBinaryNumber[LENGTH_BINARY_NUMBER - 3] = 1; // 000100 = 4
    correctBinaryNumber[LENGTH_BINARY_NUMBER - 4] = 1; // 001000 = 8

    binaryRepresentation(binaryNumber, number);

    for (int i = 0; i < LENGTH_BINARY_NUMBER; ++i)
    {
        if (binaryNumber[i] != correctBinaryNumber[i])
        {
            return false;
        }
    }
    return true;
}

bool testAddBinaryNumbers()
{
    unsigned char binaryNumber1[LENGTH_BINARY_NUMBER] = {0};
    unsigned char binaryNumber2[LENGTH_BINARY_NUMBER] = {0};

    binaryNumber1[LENGTH_BINARY_NUMBER - 3] = 1; // 000100 = 4
    binaryNumber2[LENGTH_BINARY_NUMBER - 3] = 1; // 000100 = 4

    unsigned char result[LENGTH_BINARY_NUMBER] = {0};
    unsigned char correctResult[LENGTH_BINARY_NUMBER] = {0};
    correctResult[LENGTH_BINARY_NUMBER - 4] = 1; // 001000 = 8

    addBinaryNumbers(binaryNumber1, binaryNumber2, result);

    for (int i = 0; i < LENGTH_BINARY_NUMBER; ++i)
    {
        if (result[i] != correctResult[i])
        {
            return false;
        }
    }
    return true;
}

bool testConversionFromBinaryToDecimal()
{
    unsigned char binaryNumber[LENGTH_BINARY_NUMBER] = {0};
    binaryNumber[LENGTH_BINARY_NUMBER - 3] = 1; // 000100 = 4
    binaryNumber[LENGTH_BINARY_NUMBER - 4] = 1; // 001000 = 8
    return conversionFromBinaryToDecimal(binaryNumber, LENGTH_BINARY_NUMBER) == 12;
}

int testBinaryNumber() {
    if (!testBinaryRepresentation()) {
        printf("Ошибка работы функции BinaryRepresentation.\n");
        return IncorrectBinaryForm;
    }

    if (!testAddBinaryNumbers()) {
        printf("Ошибка работы функции AddBinaryNumbers.\n");
        return IncorrectSumOfBinary;
    }

    if (!testConversionFromBinaryToDecimal()) {
        printf("Ошибка работы функции ConversionFromBinaryToDecimal.\n");
        return IncorrectDecimalForm;
    }
    return OK;
}