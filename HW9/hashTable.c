#include <stdlib.h>
#include "hashTable.h"

#define CAPACITY 31

typedef struct HashTable
{
    List *values[CAPACITY];
    int count;
    int size;
} HashTable;

HashTable *createHashTable()
{
    HashTable *newHashTable = calloc(1, sizeof(HashTable));
    if (newHashTable == NULL)
    {
        return NULL;
    }
    newHashTable->count = 0;
    newHashTable->size = CAPACITY;
    return newHashTable;
}

int hash(Value value)
{
    unsigned int result = 0;
    for (int i = 0; value[i] != '\0'; ++i)
    {
        result += value[i];
    }
    return result % CAPACITY;
}

Error insertValue(HashTable *table, Value value)
{
    if (table == NULL)
    {
        return HashTableEmpty;
    }

    List **list = &table->values[hash(value)];
    List *node = findNode(list, value);

    if (node == NULL)
    {
        ErrorList errorList = addNode(list, value);
        if (errorList == ListNotCreated_List)
        {
            return ListNotCreated;
        }
        if (errorList == MemoryAllocationError_List)
        {
            return MemoryAllocationError;
        }
        ++table->count;
        return Ok;
    }
    else
    {
        incrementAmount(node);
        return Ok;
    }
}

int maximumLength(HashTable *table, Error *error)
{
    if (table == NULL)
    {
        *error = HashTableEmpty;
        return -3;
    }

    int maximum = 0;
    int currentLength = 0;
    for (int i = 0; i < table->size; ++i)
    {
        currentLength = lengthList(&table->values[i]);
        if (currentLength > maximum)
        {
            maximum = currentLength;
        }
    }
    return maximum;
}

float averageLength(HashTable *table, Error *error)
{
    if (table == NULL)
    {
        *error = HashTableEmpty;
        return -3;
    }

    int sumsLength = 0;
    int notEmpty = 0;
    int currentLength = 0;
    for (int i = 0; i < table->size; ++i)
    {
        currentLength = lengthList(&table->values[i]);
        if (currentLength != 0)
        {
            sumsLength += currentLength;
            ++notEmpty;
        }
    }
    if (notEmpty != 0)
    {
        return (float)sumsLength / notEmpty;
    }

    return 0;

}

int numberOfElements(HashTable *table, Error *error)
{
    if (table == NULL)
    {
        *error = HashTableEmpty;
        return -3;
    }
    return table->count;
}

int numberOfSegments(HashTable *table, Error *error)
{
    if (table == NULL)
    {
        *error = HashTableEmpty;
        return -3;
    }
    return table->size;
}

Error printHashTable(HashTable *table)
{
    if (table == NULL)
    {
        return HashTableEmpty;
    }

    for (int i = 0; i < table->size; ++i)
    {
        printList(table->values[i]);
    }
    return Ok;
}

Error freeHashTable(HashTable *table)
{
    if (table == NULL)
    {
        return HashTableEmpty;
    }

    for (int i = 0; i < table->size; ++i)
    {
        freeList(table->values[i]);
    }
    free(table);
    return Ok;
}

List **getValues(HashTable *table) {
    return table->values;
}
