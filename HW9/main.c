#include <stdio.h>

#include "hashTable.h"
#include "hashTableTest.h"

#define MAXIMUM_SIZE 256

int main()
{
    if(!testHashTable())
    {
        printf("Tests failed!\n");
        return -1;
    }
    FILE *file = fopen("HW9/input.txt", "r");
    if (file == NULL)
    {
        printf("File opening error.\n");
        return -1;
    }
    HashTable *table = createHashTable();
    if (table == NULL)
    {
        fclose(file);
        printf("Table creation error.\n");
        return -1;
    }

    char buffer[MAXIMUM_SIZE] = {0};
    Error errorCode = Ok;
    while (fscanf(file, "%s", buffer) == 1)
    {
        if ((errorCode = insertValue(table, buffer)) != 0)
        {
            fclose(file);
            freeHashTable(table);
            printf("The Insert function finished with error %d.\n", errorCode);
            return -1;
        }
    }
    fclose(file);

    printf("Word frequencies in your file:\n");
    printHashTable(table);
    int tryCountElement = numberOfElements(table, &errorCode);
    if (errorCode != Ok)
    {
        freeHashTable(table);
        return -1;
    }
    int tryCountSegment = numberOfSegments(table, &errorCode);
    if (errorCode != Ok)
    {
        freeHashTable(table);
        return -1;
    }
    printf("Fill factor: %f\n", (float)tryCountElement / tryCountSegment);
    int tryCountMax = maximumLength(table, &errorCode);
    if (errorCode != Ok)
    {
        freeHashTable(table);
        return -1;
    }
    printf("Maximum list length: %d\n", tryCountMax);
    float tryCountAverage = averageLength(table, &errorCode);
    if (errorCode != Ok)
    {
        freeHashTable(table);
        return -1;
    }
    printf("Average list length: %f\n", tryCountAverage);
    freeHashTable(table);
    return 0;
}