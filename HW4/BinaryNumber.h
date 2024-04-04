#ifndef HOMEWORKS_BINARYNUMBER_H
#define HOMEWORKS_BINARYNUMBER_H

#define LENGTH_BINARY_NUMBER sizeof(int) * 8
#include <stdbool.h>

// representation of decimal number in binary form
void binaryRepresent(bool array[], int number);

// addition of two binary numbers
void addBinaryNumbers(bool firstNumber[], bool secondNumber[], bool answer[]);

// representation of binary number in decimal form
int convertFromBinaryToDecimal(bool array[], char length);

// print array on the screen
void printArray(bool array[], char length);

#endif //HOMEWORKS_BINARYNUMBER_H