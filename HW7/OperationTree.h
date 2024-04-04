#ifndef HOMEWORKS_OPERATIONTREE_H
#define HOMEWORKS_OPERATIONTREE_H

#include <stdio.h>

typedef enum { Ok, MemoryAllocationError, DivisionByZero, FileOpeningError, TestsFailed } Error;

typedef struct Tree Tree;

// Fills in the tree from the file "fileName"
// Returns:
// Ok - if everything is ok;
// MemoryAllocationError - if a memory allocation error occurred
Error fillTree(Tree **root, const char *fileName);

// Outputs the expression stored in the tree
void printExpression(Tree *tree);

// Calculates the value of the expression in the tree
int evaluateTree(Tree *tree, Error *error);

// Frees up all the memory allocated for the tree
void freeTree(Tree **root);

#endif //HOMEWORKS_OPERATIONTREE_H
