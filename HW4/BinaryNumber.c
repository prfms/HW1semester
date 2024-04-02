#include <stdio.h>
#include "BinaryNumber.h"

void printArray(unsigned char array[], char length)
{
    for (int i = 0; i < length; ++i)
    {
        printf("%d", array[i]);
    }
}

void binaryRepresentation(unsigned char array[], int number)
{
    int bit = 1;
    for (int i = LENGTH_BINARY_NUMBER - 1; i >= 0; --i)
    {
        array[i] = (number & bit) ? 1 : 0;
        bit = bit << 1;
    }
}

void addBinaryNumbers(unsigned char firstNumber[], unsigned char secondNumber[], unsigned char answer[])
{
    int temp = 0;
    int remainder = 0;
    for (int i = LENGTH_BINARY_NUMBER - 1; i >= 0; --i)
    {
        temp = firstNumber[i] + secondNumber[i] + remainder;
        answer[i] = temp & 1;
        remainder = temp >> 1;
    }
}

int conversionFromBinaryToDecimal(unsigned char array[], char length)
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