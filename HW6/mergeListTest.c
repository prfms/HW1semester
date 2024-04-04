#include "mergeListTest.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool addTest()
{
    List *head = NULL;
    int errorCode = OK;

    errorCode = addRecord(&head, "Anya", "+79999999999");
    if (!(errorCode == OK && strcmp(head->name, "Anya") == 0 && strcmp(head->phone, "+79999999999") == 0))
    {
        freeList(&head);
        return false;
    }

    errorCode = addRecord(&head, "Darya", "+11000028984");
    if (!(errorCode == OK && strcmp(head->name, "Darya") == 0 && strcmp(head->phone, "+11000028984") == 0 &&
          strcmp(head->next->name, "Anya") == 0 && strcmp(head->next->phone, "+79999999999") == 0))
    {
        freeList(&head);
        return false;
    }

    errorCode = addRecord(&head,  "Bella", "+789286544040");
    if (!(errorCode == OK && strcmp(head->name, "Bella") == 0 && strcmp(head->phone, "+789286544040") == 0 &&
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
    head->name = strdup("Bella");
    head->phone = strdup("+789286544040");

    head->next = calloc(1, sizeof(List));
    if (head->next == NULL)
    {
        free(head->name);
        free(head->phone);
        return false;
    }
    head->next->name = strdup("Darya");
    head->next->phone = strdup("+11000028984");

    head->next->next = calloc(1, sizeof(List));
    if (head->next->next == NULL)
    {
        free( head->next->name);
        free(head->next->phone);
        return false;
    }
    head->next->next->name = strdup("Anya");
    head->next->next->phone = strdup("+79999999999");

    mergeSort(&head, CompareByName);
    if (!(strcmp(head->name, "Anya") == 0 && strcmp(head->phone, "+79999999999") == 0 &&
          strcmp(head->next->name, "Bella") == 0 && strcmp(head->next->phone, "+789286544040") == 0 &&
          strcmp(head->next->next->name, "Darya") == 0 && strcmp(head->next->next->phone, "+11000028984") == 0))
    {
        freeList(&head);
        return false;
    }
    mergeSort(&head, CompareByPhone);
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