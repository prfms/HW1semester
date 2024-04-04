#ifndef HOMEWORKS_BINARYNUMBER_H
#define HOMEWORKS_BINARYNUMBER_H

#define LENGTH_BINARY_NUMBER sizeof(int) * 8
#include <stdbool.h>

// представление десятичного числа в двоичной системе счисления
void binaryRepresent(bool array[], int number);

// сложение двух двоичных чисел, результат - двоичное число
void addBinaryNumbers(bool firstNumber[], bool secondNumber[], bool answer[]);

// представление двоичного числа в десятичной системе счисления
int convertFromBinaryToDecimal(bool array[], char length);

// вывод массива
void printArray(bool array[], char length);

#endif //HOMEWORKS_BINARYNUMBER_H