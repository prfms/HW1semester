#ifndef HOMEWORKS1SEMESTER_LIST_H
#define HOMEWORKS1SEMESTER_LIST_H

typedef enum {
    ListNotCreated_List = -1,
    MemoryAllocationError_List = -2,
    Ok_List = 0
} ErrorList;

typedef char *Value;

typedef struct List List;

// returns the node by the specified Value, if there is no such returns NULL
List *findNode(List **list, Value value);

// Adds the value to the list
ErrorList addNode(List **list, Value value);

// Length list
int lengthList(List **list);

// Outputs a list
void printList(List *list);

// Frees up all the memory allocated for the list
void freeList(List *list);

//get value from list
Value getValueFromList(List *list);

// get amount from list
int getAmountFromList(List *list);

// increase the amount by one
void incrementAmount(List *list);

#endif //HOMEWORKS1SEMESTER_LIST_H
