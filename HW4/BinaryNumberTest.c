#include <stdbool.h>
#include <stdio.h>
#include "BinaryNumber.h"

bool testBinaryRepresentation()
{
    int number = 12;
    unsigned char binaryNumber[lengthBinaryNumber] = {0};
    unsigned char correctBinaryNumber[lengthBinaryNumber] = {0};
    correctBinaryNumber[lengthBinaryNumber - 3] = 1;
    correctBinaryNumber[lengthBinaryNumber - 4] = 1;

    binaryRepresentation(binaryNumber, number);

    for (int i = 0; i < lengthBinaryNumber; ++i)
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
    unsigned char binaryNumber1[lengthBinaryNumber] = {0};
    unsigned char binaryNumber2[lengthBinaryNumber] = {0};

    binaryNumber1[lengthBinaryNumber - 3] = 1;
    binaryNumber2[lengthBinaryNumber - 3] = 1;

    unsigned char result[lengthBinaryNumber] = {0};
    unsigned char correctResult[lengthBinaryNumber] = {0};
    correctResult[lengthBinaryNumber - 4] = 1;

    addBinaryNumbers(binaryNumber1, binaryNumber2, result);

    for (int i = 0; i < lengthBinaryNumber; ++i)
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
    unsigned char binaryNumber[lengthBinaryNumber] = {0};
    binaryNumber[lengthBinaryNumber - 3] = 1;
    binaryNumber[lengthBinaryNumber - 4] = 1;
    return conversionFromBinaryToDecimal(binaryNumber, lengthBinaryNumber) == 12;
}

int testBinaryNumber() {
    if (!testBinaryRepresentation()) {
        printf("Ошибка работы функции BinaryRepresentation.\n");
        return -1;
    }

    if (!testAddBinaryNumbers()) {
        printf("Ошибка работы функции AddBinaryNumbers.\n");
        return -2;
    }

    if (!testConversionFromBinaryToDecimal()) {
        printf("Ошибка работы функции ConversionFromBinaryToDecimal.\n");
        return -3;
    }
}