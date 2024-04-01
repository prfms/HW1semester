#ifndef HOMEWORKS_BINARYNUMBER_H
#define HOMEWORKS_BINARYNUMBER_H
#define lengthBinaryNumber sizeof(int) * 8
// представление десятичного числа в двоичной системе счисления
void binaryRepresentation(unsigned char array[], int number);
// сложение двух двоичных чисел, результат - двоичное число
void addBinaryNumbers(unsigned char firstNumber[], unsigned char secondNumber[], unsigned char answer[]);
// представление двоичного числа в десятичной системе счисления
int conversionFromBinaryToDecimal(unsigned char array[], char length);
// вывод массива
void printArray(unsigned char array[], char length);
// Код ошибки:
// -1 - неверная конвертация в двоичную форму
// -2 - неверное сложение двоичных чисел
// -3 - неверная конвертация в десятичную форму
int testBinaryNumber();
#endif //HOMEWORKS_BINARYNUMBER_H