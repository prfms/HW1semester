#define sizeInsertionSort 10
#include <stdio.h>
#include "QuickSort.h"

void printArray(int array[], int lengthArray)
{
    printf("[ ");
    for (int i = 0; i < lengthArray; ++i)
    {
        printf("%d ", array[i]);
    }
    printf("]");
}

void swap(int *firstNumber, int *secondNumber)
{
    int temp = *firstNumber;
    *firstNumber = *secondNumber;
    *secondNumber = temp;
}

int partition(int array[], int leftIndex, int rightIndex)
{
    for (int current = leftIndex; current < rightIndex; ++current)
    {
        if (array[rightIndex] > array[current])
        {
            swap(&array[current], &array[leftIndex]);
            ++leftIndex;
        }
    }

    swap(&array[rightIndex], &array[leftIndex]);

    return leftIndex;
}

void insertsSort(int array[], int leftIndex, int rightIndex)
{
    for (int i = leftIndex; i < rightIndex; ++i)
    {
        int j = i + 1;

        while (j > leftIndex && array[j - 1] > array[j])
        {
            swap(&array[j - 1], &array[j]);
            --j;
        }
    }
}

void quickSort(int array[], int leftIndex, int rightIndex)
{
    if (rightIndex - leftIndex <= sizeInsertionSort - 2)
    {
        insertsSort(array, leftIndex, rightIndex);
    }
    else
    {
        int middleIndex = partition(array, leftIndex, rightIndex);
        quickSort(array, leftIndex, middleIndex - 1);
        quickSort(array, middleIndex + 1, rightIndex);
    }
}

