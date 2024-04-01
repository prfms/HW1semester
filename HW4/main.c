#include <stdio.h>
#include <locale.h>
#include "BinaryNumber.h"

int main(){
    setlocale(LC_ALL, "");

    int firstNumber = 0;
    int secondNumber = 0;
    int scanResFirstNumber = 0;
    int scanResSecondNumber = 0;

    printf("Введите два числа:\n");
    do
    {
        scanResFirstNumber = scanf("%d", &firstNumber);
        scanResSecondNumber = scanf("%d", &secondNumber);

        if (!scanResFirstNumber || !scanResSecondNumber)
        {
            printf("Ошибка ввода. Попробуйте еще раз.\n");
            scanf("%*[^\n]");
        }

    } while (!scanResFirstNumber || !scanResSecondNumber);

    unsigned char binaryFirstNumber[lengthBinaryNumber] = {0};
    unsigned char binarySecondNumber[lengthBinaryNumber] = {0};
    binaryRepresentation(binaryFirstNumber, firstNumber);
    binaryRepresentation(binarySecondNumber, secondNumber);

    printf("\n ");
    printArray(binaryFirstNumber, lengthBinaryNumber);
    printf(" (%d)\n+\n ", firstNumber);
    printArray(binarySecondNumber, lengthBinaryNumber);
    printf(" (%d) \n --------------------------------\n ", secondNumber);

    unsigned char binarySum[lengthBinaryNumber] = {0};
    addBinaryNumbers(binaryFirstNumber, binarySecondNumber, binarySum);

    int decimalSum = conversionFromBinaryToDecimal(binarySum, lengthBinaryNumber);

    printArray(binarySum, lengthBinaryNumber);
    printf(" (%d)", decimalSum);
    printf("\n\nСумма %d и %d равна %d.\n", firstNumber, secondNumber, decimalSum);

    return 0;
}