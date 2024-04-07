#include <stdio.h>
#include <string.h>

#include "hashTableTest.h"

#define BUFFER_SIZE 256

bool testHashTable()
{
    FILE *file = fopen("HW9/data.txt", "r");
    if (file == NULL) {
        printf("File opening error.\n");
        return false;
    }
    HashTable *table = createHashTable();
    if (table == NULL) {
        fclose(file);
        return false;
    }

    char buffer[BUFFER_SIZE] = {0};
    Error errorCode = Ok;
    while (fscanf(file, "%s", buffer) == 1)
    {
        if ((errorCode = insertValue(table, buffer)) != 0)
        {
            fclose(file);
            freeHashTable(table);
            return false;
        }
    }
    fclose(file);

    List **values = getValues(table);
    List *list14 = values[14];
    List *list17 = values[17];
    bool test1 = strcmp(getValueFromList(list14), "test") == 0;;
    bool test2 = strcmp(getValueFromList(list17), "hash") == 0;;
    bool test3 = getAmountFromList(list14) == 1;
    bool test4 = getAmountFromList(list17) == 2;
    return test1 && test2 && test3 && test4;
}
