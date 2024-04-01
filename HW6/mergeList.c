#include "mergeList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct List
{
    char *name;
    char *phone;
    struct List *next;
} List;

Error addRecord(List **head, char *name, char *phone)
{
    List *record = calloc(1, sizeof(List));
    if (record == NULL)
    {
        return MemoryAllocationError;
    }
    record->name = strdup(name);
    record->phone = strdup(phone);
    record->next = *head;
    *head = record;
    return OK;
}

void freeList(List **head)
{
    List *tmp = NULL;
    if (head == NULL)
    {
        return;
    }
    while (*head != NULL)
    {
        tmp = *head;
        *head = (*head)->next;
        free(tmp->name);
        free(tmp->phone);
        free(tmp);
    }
}

void printList(List *head)
{
    while (head != NULL)
    {
        printf("%s %s\n", head->name, head->phone);
        head = head->next;
    }
}

int compare(List *left, List *right, int TypeOfCompare)
{
    TypeOfCompare == CompareByName ? strcmp(left->name, right->name) : strcmp(left->phone, right->phone);
}

void split(List *sourceList, List **leftList, List **rightList)
{
    if (sourceList == NULL || sourceList->next == NULL)
    {
        (*leftList) = sourceList;
        (*rightList) = NULL;
        return;
    }

    List *slow = sourceList;
    List *fast = sourceList->next;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
    }

    (*leftList) = sourceList;
    (*rightList) = slow->next;
    slow->next = NULL;
}

void merge(List *leftList, List *rightList, List **resultList, int typeOfCompare)
{
    *resultList = NULL;
    if (leftList == NULL)
    {
        *resultList = rightList;
        return;
    }
    if (rightList == NULL)
    {
        *resultList = leftList;
        return;
    }

    if (compare(leftList, rightList, typeOfCompare) < 0)
    {
        (*resultList) = leftList;
        leftList = leftList->next;
    }
    else
    {
        (*resultList) = rightList;
        rightList = rightList->next;
    }
    List *head = *resultList;

    while (leftList != NULL && rightList != NULL)
    {
        if (compare(leftList, rightList, typeOfCompare) < 0)
        {
            (*resultList)->next = leftList;
            leftList = leftList->next;
        }
        else
        {
            (*resultList)->next = rightList;
            rightList = rightList->next;
        }
        *resultList = (*resultList)->next;
    }

    if (rightList == NULL)
    {
        (*resultList)->next = leftList;
    }
    if (leftList == NULL)
    {
        (*resultList)->next = rightList;
    }

    *resultList = head;
}

void mergeSort(List **head, int typeOfCompare)
{
    List *leftList = NULL;
    List *rightList = NULL;
    if ((*head == NULL) || ((*head)->next == NULL))
    {
        return;
    }
    split(*head, &leftList, &rightList);
    mergeSort(&leftList, typeOfCompare);
    mergeSort(&rightList, typeOfCompare);
    merge(leftList, rightList, head, typeOfCompare);
}