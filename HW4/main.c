#include <stdio.h>
#include <locale.h>
#include "BinaryNumber.h"
#include "BinaryNumberTest.h"

int main()
{
    setlocale(LC_ALL, "");

    if (testBinaryNumber())
    {
        printf("����� �� ������!\n");
        return TestsFailed;
    }
    int firstNumber = 0;
    int secondNumber = 0;
    int scanResFirstNumber = 0;
    int scanResSecondNumber = 0;

    printf("������� ��� �����:\n");
    do
    {
        scanResFirstNumber = scanf("%d", &firstNumber);
        scanResSecondNumber = scanf("%d", &secondNumber);

        if (!scanResFirstNumber || !scanResSecondNumber)
        {
            printf("������ �����. ������� ����� ������ ����� �����. ���������� ��� ���!\n");
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
    printf("\n\n ����� %d � %d ����� %d.\n", firstNumber, secondNumber, decimalSum);

    return 0;
}