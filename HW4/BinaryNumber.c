#include <stdio.h>
#include "BinaryNumber.h"

void printArray(bool array[], char length)
{
    for (int i = 0; i < length; ++i)
    {
        printf("%d", array[i]);
    }
}

void binaryRepresent(bool array[], int number)
{
    int bit = 1;
    for (int i = LENGTH_BINARY_NUMBER - 1; i >= 0; --i)
    {
        array[i] = (number & bit) ? 1 : 0;
        bit = bit << 1;
    }
}

void addBinaryNumbers(bool firstNumber[], bool secondNumber[], bool answer[])
{
    int remainder = 0;
    for (int i = LENGTH_BINARY_NUMBER - 1; i >= 0; --i)
    {
        int temp = firstNumber[i] + secondNumber[i] + remainder;
        answer[i] = temp & 1;
        remainder = temp >> 1;
    }
}

int convertFromBinaryToDecimal(bool array[], char length)
{
    int decimalResult = 0;
    int power = 1;
    for (int i = length - 1; i >= 0; --i)
    {
        decimalResult += array[i] * power;
        power <<= 1;
    }
    return decimalResult;
}