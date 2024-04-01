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
// ��������� ������ ������� �� �����
// ��� ������: -1 ������ ��������� ������, -2 ������ ������� � �����
Error fillList(List **head, char *pathToFile);
// ���������� ������ � ������
// ��� ������ -1, ���� ������ ���� ��� ������ ��������� ������
Error addRecord(List **head, char *name, char *phone);
// ������� ������
void freeList(List **head);
// ������� ������
void printList(List *head);
// ���������� ��������
void mergeSort(List **head, int typeOfCompare);
// ����� ��� ������� addRecord � mergeSort
bool tests();
#endif //HOMEWORKS_MERGELIST_H
