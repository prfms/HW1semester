﻿#include <stdlib.h>

#include "List.h"

typedef struct ListElement
{
    struct ListElement* next;
    unsigned int value;
} ListElement;

typedef struct List
{
    ListElement *head;
} List;

List* createList()
{
    List *temp = malloc(sizeof(List));
    if (temp == NULL)
    {
        return NULL;
    }

    temp->head = NULL;

    return temp;
}

ListElement* createListElement(unsigned int value)
{
    ListElement *tempElement = malloc(sizeof(ListElement));
    if (tempElement == NULL)
    {
        return NULL;
    }

    tempElement->value = value;
    tempElement->next = NULL;

    return tempElement;
}

ListError addValue(List *list, unsigned int value)
{
    if (list == NULL)
    {
        return ListNotFound;
    }

    ListElement *tempElement = createListElement(value);
    if (tempElement == NULL)
    {
        return ListMemoryAllocationError;
    }

    tempElement->next = list->head;
    list->head = tempElement;

    return ListOk;
}

ListElement* getFirstListElement(List *list)
{
    if (list == NULL)
    {
        return NULL;
    }

    return list->head;
}

ListElement* getNextElement(ListElement* element)
{
    if (element == NULL)
    {
        return NULL;
    }

    return element->next;
}

unsigned int getListElementValue(ListElement* element, ListError *errorCode)
{
    if (element == NULL)
    {
        *errorCode = ListElementIsNotFound;
        return 0;
    }

    return element->value;
}

void deleteList(List **list)
{
    if (list == NULL || *list == NULL)
    {
        return;
    }

    ListElement *currentElement = (*list)->head;
    ListElement *previousElement = NULL;
    while (currentElement != NULL)
    {
        previousElement = currentElement;
        currentElement = currentElement->next;

        free(previousElement);
    }

    free(*list);
    *list = NULL;
}