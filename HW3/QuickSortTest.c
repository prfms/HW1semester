#include <stdbool.h>
#include "QuickSortTest.h"

bool testReversedArray()
{
    int array[5] = {5, 4, 3, 2, 1};
    quickSort(array, 0, 4);
    for (int i = 0; i < 5; ++i)
    {
        if (array[i] != i + 1) return false;
    }
    return true;
}

bool testNegativeValueArray()
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

bool testConstantArray()
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

bool testQuickSort()
{
    return testReversedArray() && testNegativeValueArray() && testConstantArray();
}
