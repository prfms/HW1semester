#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "OperationTree.h"

typedef struct Tree
{
    char operation;
    int number;
    struct Tree *leftChild;
    struct Tree *rightChild;
} Tree;

Error fillTree(Tree **root, const char *fileName)
{
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        return FileOpeningError;
    }
    if (feof(file))
    {
        fclose(file);
        return FileOpeningError;
    }
    bool isContinue = true;
    while (isContinue)
    {
        char currentCharacter = getc(file);
        switch (currentCharacter)
        {
            case ' ':
                continue;

            case '(':
                continue;

            case ')':
                isContinue = false;
                break;
            case '+':
            case '*':
            case '/':
                (*root) = calloc(1, sizeof(Tree));
                if ((*root) == NULL)
                {
                    fclose(file);
                    return MemoryAllocationError;
                }
                (*root)->operation = currentCharacter;

                if (fillTree(&(*root)->leftChild, fileName) == MemoryAllocationError)
                {
                    freeTree(root);
                    fclose(file);
                    return MemoryAllocationError;
                }

                if (fillTree(&(*root)->rightChild, fileName) == MemoryAllocationError)
                {
                    freeTree(root);
                    fclose(file);
                    return MemoryAllocationError;
                }
                break;
            case '-':
                (*root) = calloc(1, sizeof(Tree));
                if ((*root) == NULL)
                {
                    fclose(file);
                    return MemoryAllocationError;
                }

                char nextElement = getc(file);
                ungetc(nextElement, file);
                if (nextElement >= '0' && nextElement <= '9') // Checking if it's a negative number
                {
                    (*root)->operation = -1; // The indicator that this node is a number
                    ungetc(currentCharacter, file);
                    fscanf(file, "%d", &(*root)->number);
                    isContinue = false;
                    break;
                }

                (*root)->operation = currentCharacter;
                if (fillTree(&(*root)->leftChild, fileName) == MemoryAllocationError)
                {
                    fclose(file);
                    return MemoryAllocationError;
                }

                if (fillTree(&(*root)->rightChild, fileName) == MemoryAllocationError)
                {
                    fclose(file);
                    return MemoryAllocationError;
                }
                break;

            default: // Numbers
                (*root) = calloc(1, sizeof(Tree));
                if ((*root) == NULL)
                {
                    fclose(file);
                    return MemoryAllocationError;
                }

                (*root)->operation = -1; // The indicator that this node is a number
                ungetc(currentCharacter, file);
                fscanf(file, "%d", &(*root)->number);
                isContinue = false;
                break;
        }
    }
    fclose(file);
    return Ok;
}

int evaluateTree(Tree *tree, Error *error)
{
    if (tree == NULL)
    {
        return 0;
    }
    if (error != 0)
    {
        return -1;
    }
    int leftValue = evaluateTree(tree->leftChild, error);
    int rightValue = evaluateTree(tree->rightChild, error);

    switch (tree->operation)
    {
        case -1: // Numbers
            return tree->number;

        case '+':
            return leftValue + rightValue;

        case '-':
            return leftValue - rightValue;

        case '*':
            return leftValue * rightValue;

        case '/':
            if (rightValue == 0)
            {
                *error = DivisionByZero;
                return -1;
            }
            return leftValue / rightValue;
    }
}

void printExpression(Tree *tree)
{
    if (tree == NULL)
    {
        return;
    }

    if (tree->operation == -1) // A number
    {
        printf("%d ", tree->number);
    }
    else
    {
        printf("( %c ", tree->operation);
        printExpression(tree->leftChild);
        printExpression(tree->rightChild);
        printf(") ");
    }
}

void freeTree(Tree **root)
{
    if ((*root) == NULL)
    {
        return;
    }

    freeTree(&(*root)->leftChild);
    freeTree(&(*root)->rightChild);
    free(*root);
    *root = NULL;
}
