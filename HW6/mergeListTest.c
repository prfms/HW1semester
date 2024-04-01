#include "mergeList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define maxLength 256

Error fillList(List **head, char *pathToFile)
{
    if (head == NULL)
    {
        return -1;
    }
    FILE *file = fopen(pathToFile, "r");
    if (file == NULL)
    {
        return -2;
    }
    int errorCode = 0;
    while (!feof(file))
    {
        char name[maxLength] = {0};
        char phone[maxLength] = {0};
        fscanf(file, "%s %s", name, phone);
        errorCode = addRecord(head, name, phone);
        if (errorCode != 0)
        {
            return errorCode;
        }
    }
    return 0;
}

bool addTest()
{
    List *head = NULL;
    int errorCode = 0;

    errorCode = addRecord(&head, "Anya", "+79999999999");
    if (!(errorCode == 0 && strcmp(head->name, "Anya") == 0 && strcmp(head->phone, "+79999999999") == 0))
    {
        freeList(&head);
        return false;
    }

    errorCode = addRecord(&head, "Darya", "+11000028984");
    if (!(errorCode == 0 && strcmp(head->name, "Darya") == 0 && strcmp(head->phone, "+11000028984") == 0 &&
          strcmp(head->next->name, "Anya") == 0 && strcmp(head->next->phone, "+79999999999") == 0))
    {
        freeList(&head);
        return false;
    }

    errorCode = addRecord(&head,  "Bella", "+789286544040");
    if (!(errorCode == 0 && strcmp(head->name, "Bella") == 0 && strcmp(head->phone, "+789286544040") == 0 &&
          strcmp(head->next->name, "Darya") == 0 && strcmp(head->next->phone, "+11000028984") == 0 &&
          strcmp(head->next->next->name, "Anya") == 0 && strcmp(head->next->next->phone, "+79999999999") == 0))
    {
        freeList(&head);
        return false;
    }

    freeList(&head);
    return true;
}

bool mergeSortTest()
{
    List *head = calloc(1, sizeof(List));
    if (head == NULL)
    {
        return false;
    }
    strcpy(head->name, "Bella");
    strcpy(head->phone, "+789286544040");

    head->next = calloc(1, sizeof(List));
    if (head->next == NULL)
    {
        return false;
    }
    strcpy(head->next->name, "Darya");
    strcpy(head->next->phone, "+11000028984");

    head->next->next = calloc(1, sizeof(List));
    if (head->next->next == NULL)
    {
        return false;
    }
    strcpy(head->next->next->name, "Anya");
    strcpy(head->next->next->phone, "+79999999999");

    mergeSort(&head, 0);
    if (!(strcmp(head->name, "Anya") == 0 && strcmp(head->phone, "+79999999999") == 0 &&
          strcmp(head->next->name, "Bella") == 0 && strcmp(head->next->phone, "+789286544040") == 0 &&
          strcmp(head->next->next->name, "Darya") == 0 && strcmp(head->next->next->phone, "+11000028984") == 0))
    {
        freeList(&head);
        return false;
    }
    mergeSort(&head, 1);
    if (!(strcmp(head->name, "Darya") == 0 && strcmp(head->phone, "+11000028984") == 0 &&
          strcmp(head->next->name, "Bella") == 0 && strcmp(head->next->phone,"+789286544040") == 0 &&
          strcmp(head->next->next->name, "Anya") == 0 && strcmp(head->next->next->phone, "+79999999999") == 0))
    {
        freeList(&head);
        return false;
    }

    freeList(&head);
    return true;
}

bool tests()
{
    return addTest() && mergeSortTest();
}