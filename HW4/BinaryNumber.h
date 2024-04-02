#ifndef HOMEWORKS_BINARYNUMBER_H
#define HOMEWORKS_BINARYNUMBER_H
#define LENGTH_BINARY_NUMBER sizeof(int) * 8

typedef enum
{
    OK = 0,
    IncorrectBinaryForm = -1,
    IncorrectSumOfBinary = -2,
    IncorrectDecimalForm = -3,
    TestsFailed = -100
} Error;

// представление десятичного числа в двоичной системе счисления
void binaryRepresentation(unsigned char array[], int number);

// сложение двух двоичных чисел, результат - двоичное число
void addBinaryNumbers(unsigned char firstNumber[], unsigned char secondNumber[], unsigned char answer[]);

// представление двоичного числа в десятичной системе счисления
int conversionFromBinaryToDecimal(unsigned char array[], char length);

// вывод массива
void printArray(unsigned char array[], char length);

#endif //HOMEWORKS_BINARYNUMBER_H