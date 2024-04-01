#include <stdbool.h>
#ifndef HOMEWORKS_MERGELIST_H
#define HOMEWORKS_MERGELIST_H
#define maxLength 256
typedef int Error;

typedef struct List
{
    char name[maxLength];
    char phone[maxLength];
    struct List *next;
} List;
// заполнение списка значениями из файла
Error fillList(List **head, char *pathToFile);
// добавление записи
Error addRecord(List **head, char *name, char *phone);
// очищение списка
void freeList(List **head);
// вывод списка
void printList(List *head);
// сортировка слиянием
void mergeSort(List **head, int typeOfCompare);
// тестирование addRecord и mergeSort
bool tests();
#endif //HOMEWORKS_MERGELIST_H