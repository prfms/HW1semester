#include <stdio.h>
#include <locale.h>
#include "BinaryNumber.h"
#include "BinaryNumberTest.h"

int main()
{
    setlocale(LC_ALL, "");

    if (testBinaryNumber())
    {
        printf("Тесты не прошли!\n");
        return TestsFailed;
    }
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
            printf("Ошибка ввода. Вводить можно только целые числа. Попробуйте еще раз!\n");
            scanf("%*[^\n]");
        }

    } while (!scanResFirstNumber || !scanResSecondNumber);

    bool binaryFirstNumber[LENGTH_BINARY_NUMBER] = {0};
    bool binarySecondNumber[LENGTH_BINARY_NUMBER] = {0};
    binaryRepresent(binaryFirstNumber, firstNumber);
    binaryRepresent(binarySecondNumber, secondNumber);

    printf("\n ");
    printArray(binaryFirstNumber, LENGTH_BINARY_NUMBER);
    printf(" (%d)\n+\n ", firstNumber);
    printArray(binarySecondNumber, LENGTH_BINARY_NUMBER);
    printf(" (%d) \n --------------------------------\n ", secondNumber);

    bool binarySum[LENGTH_BINARY_NUMBER] = {0};
    addBinaryNumbers(binaryFirstNumber, binarySecondNumber, binarySum);

    int decimalSum = convertFromBinaryToDecimal(binarySum, LENGTH_BINARY_NUMBER);

    printArray(binarySum, LENGTH_BINARY_NUMBER);
    printf(" (%d)", decimalSum);
    printf("\n\n Сумма %d и %d равна %d.\n", firstNumber, secondNumber, decimalSum);

    return 0;
}