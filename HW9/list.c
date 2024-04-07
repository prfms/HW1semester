#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "list.h"

typedef struct List
{
    Value value;
    int amount;
    struct List *next;
} List;

List *findNode(List **list, Value value)
{
    if (list == NULL)
    {
        return NULL;
    }

    while (*list != NULL && strcmp((*list)->value, value) != 0)
    {
        list = &(*list)->next;
    }
    return *list;
}

ErrorList addNode(List **list, Value value)
{
    if (list == NULL)
    {
        return ListNotCreated_List;
    }

    while (*list != NULL)
    {
        list = &(*list)->next;
    }

    List *newNode = calloc(1, sizeof(List));
    if (newNode == NULL)
    {
        return MemoryAllocationError_List;
    }
    newNode->value = calloc(strlen(value) + 1, sizeof(char));
    if (newNode->value == NULL)
    {
        return MemoryAllocationError_List;
    }
    strcpy(newNode->value, value);
    newNode->amount = 1;
    *list = newNode;
    return Ok_List;
}

int lengthList(List **list)
{
    int counter = 0;
    if (list == NULL)
    {
        return counter;
    }
    while (*list != NULL)
    {
        list = &(*list)->next;
        ++counter;
    }
    return counter;
}

void printList(List *list)
{
    if (list == NULL)
    {
        return;
    }
    while (list != NULL)
    {
        printf("| ");
        printf("%s %d | ", list->value, list->amount);
        list = list->next;
    }
    printf("\n");
}

void freeList(List *list)
{
    if (list == NULL)
    {
        return;
    }

    freeList(list->next);
    free(list->value);
    free(list);
}

Value getValueFromList(List *list)
{
    if (list != NULL) {
        return list->value;
    } else {
        return NULL;
    }
}

int getAmountFromList(List *list)
{
    if (list != NULL)
    {
        return list->amount;
    }
    return 0;

}

void incrementAmount(List *list)
{
    if (list != NULL)
    {
        ++(list->amount);
    }
    return;
}