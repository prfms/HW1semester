#ifndef HOMEWORKS1SEMESTER_HASHTABLE_H
#define HOMEWORKS1SEMESTER_HASHTABLE_H

#include "list.h"

typedef enum
{
    Ok = 0,
    ListNotCreated = -1,
    MemoryAllocationError = -2,
    HashTableEmpty = -3
} Error;

typedef char *Value;

typedef struct HashTable HashTable;

//create hashtable
HashTable *createHashTable();

// Adds a value to the hash table
Error insertValue(HashTable *table, Value value);

// Outputs a hash table
Error printHashTable(HashTable *table);

// Frees up all the memory allocated for the hash table
Error freeHashTable(HashTable *table);

// maximum length of chain in hashtable
int maximumLength(HashTable *table, Error *error);

// average length of chain in hashtable
float averageLength(HashTable *table, Error *error);

// the number of elements in the hash table
int numberOfElements(HashTable *table, Error *error);

// the number of segments in the hash table
int numberOfSegments(HashTable *table, Error *error);

// get values from the table
List **getValues(HashTable *table);

#endif //HOMEWORKS1SEMESTER_HASHTABLE_H
