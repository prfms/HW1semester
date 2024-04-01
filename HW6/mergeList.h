#ifndef HOMEWORKS_MERGELIST_H
#define HOMEWORKS_MERGELIST_H
#include <stdbool.h>
#define MAX_LENGHT 256

typedef enum
{
    CompareByName = 0,
    CompareByPhone = 1
} TypeOfCompare;

typedef enum
{
    OK = 0,
    MemoryAllocationError = -1,
    FileNotFound = -2,
    TestsFailed = -100
} Error;

typedef struct List List;

// добавление записи
Error addRecord(List **head, char *name, char *phone);

// очищение списка
void freeList(List **head);

// вывод списка
void printList(List *head);

// сортировка слиянием
void mergeSort(List **head, int typeOfCompare);

#endif //HOMEWORKS_MERGELIST_H