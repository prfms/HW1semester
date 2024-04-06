#ifndef HOMEWORKS1SEMESTER_LIST_H
#define HOMEWORKS1SEMESTER_LIST_H

#include <stdbool.h>

typedef enum
{
    ListNotFound = -1,
    ListOk = 0,
    ListMemoryAllocationError = 1,
    ListElementIsNotFound = 2
} ListError;

typedef struct List List;

typedef struct ListElement ListElement;

// create list
List* createList();

// add value to list
// return 1 if not enough memory
// return 0 if ok
// return -1 if list doesn't exist
ListError addValue(List *list, unsigned int value);

// returns pointer to the first list element
ListElement* getFirstListElement(List *list);

// returns pointer to next list element, it may be NULL if it's the last one
ListElement* getNextElement(ListElement* element);

// returns value of list element by its pointer
// errorCode gets 2 if list element doesn't exist
// errorCode stays 0 if all is ok
unsigned int getListElementValue(ListElement* element, ListError *errorCode);

// deallocate list's memory
void deleteList(List **list);

#endif //HOMEWORKS1SEMESTER_LIST_H
