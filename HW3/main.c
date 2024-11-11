#include <stdbool.h>
#include <stdio.h>
#include <locale.h>
#include "QuickSort.h"
#include "QuickSortTest.h"
#define ARRAY_SIZE_BOUND 1000

int main()
{
    setlocale(LC_ALL, "");
    if (!testQuickSort()){
        return -1;
    }
    int array[ARRAY_SIZE_BOUND] = {0};
    int arraySize = 0;
    int scanResult = 0;
    bool isCorrectInput = true;

    do
    {
        printf("Введите размер массива: ");
        scanResult = scanf("%d", &arraySize);

        isCorrectInput = true;

        if (!scanResult || arraySize < 1 || arraySize > ARRAY_SIZE_BOUND)
        {
            printf("Некорректный ввод (Размер положительный и не больше чем %d). Попробуйте снова.\n", ARRAY_SIZE_BOUND);
            scanf_s("%*[^\n]");

            isCorrectInput = false;
        }
    } while (!isCorrectInput);

    printf("Введите массив:\n");
    for (int i = 0; i < arraySize; ++i)
    {
        do
        {
            scanResult = scanf("%d", &array[i]);

            if (!scanResult)
            {
                printf("Некорректный ввод. Попробуйте снова.\n");
                scanf_s("%*[^\n]");
            }
        } while (!scanResult);
    }
    quickSort(array, 0, arraySize - 1);
    printf("Отсортированный массив:\n");
    printArray(array, arraySize);
    return 0;
}