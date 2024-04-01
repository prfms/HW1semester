#include <stdio.h>
#include "mergeList.c"
#include "mergeListTest.c"

// функция для вывода ошибок
void printErrors(Error errorCode)
{
    switch (errorCode)
    {
        case OK:
            break;
        case MemoryAllocationError:
            printf("Memory allocation error!\n");
            break;
        case FileNotFound:
            printf("Input file is not found!\n");
            break;
        case TestsFailed:
            printf("Tests have failed!\n");
            break;
    }
}

int main()
{
    if (!tests())
    {
        printErrors(TestsFailed);
        return TestsFailed;
    }
    List *head = NULL;
    int errorCode = fillList(&head, "HW6/input.txt");
    if (errorCode != OK)
    {
        printErrors(errorCode);
        return errorCode;
    }
    int typeOfCompare = 0; // 0 - name, 1 - phone
    int scanResult = 0;
    while (!scanResult || !(typeOfCompare >= 0 && typeOfCompare <= 1))
    {
        printf("Enter the type of compare for your phonebook (0 - name, 1 - phone):");
        scanResult = scanf("%d", &typeOfCompare);
        if (!scanResult || !(typeOfCompare >= 0 && typeOfCompare <= 1))
        {
            printf("Incorrect input! Number 0 or 1 is required. Try again!\n");
            scanf("%*[^\n]");
        }
    }

    mergeSort(&head, typeOfCompare);
    printList(head);
    freeList(&head);
    return 0;
}