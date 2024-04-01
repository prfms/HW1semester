#include <stdbool.h>
#include "QuickSort.h"

bool testQuickSort1()
{
    int array[5] = {5, 4, 3, 2, 1};
    quickSort(array, 0, 4);
    for (int i = 0; i < 5; ++i)
    {
        if (array[i] != i + 1) return false;
    }
    return true;
}

bool testQuickSort2()
{
    int array[4] = {-3, 0, -1, -2};
    int correctArray[4] = {-3, -2, -1, 0};

    quickSort(array, 0, 3);

    for (int i = 0; i < 4; ++i)
    {
        if (array[i] != correctArray[i])
        {
            return false;
        }
    }
    return true;
}

bool testQuickSort3()
{
    int array[6] = {1, 1, 1, 1, 1, 1};

    quickSort(array, 0, 5);

    for (int i = 0; i < 6; ++i)
    {
        if (array[i] != 1)
        {
            return false;
        }
    }
    return true;
}

int testQuickSort()
{
    if (!testQuickSort1()) return -1;
    if (!testQuickSort2()) return -2;
    if (!testQuickSort3()) return -3;
    return 0;
}
