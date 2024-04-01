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
// заполняет список данными из файла
// Код ошибки: -1 ошибка выделения памяти, -2 ошибка доступа к файлу
Error fillList(List **head, char *pathToFile);
// добавление записи в список
// код ошибки -1, если список пуст или ошибка выделения памяти
Error addRecord(List **head, char *name, char *phone);
// очищает список
void freeList(List **head);
// выводит список
void printList(List *head);
// сортировка слиянием
void mergeSort(List **head, int typeOfCompare);
// тесты для функций addRecord и mergeSort
bool tests();
#endif //HOMEWORKS_MERGELIST_H
