#include <stdio.h>
#include "OperationTree.h"
#include "OperationTreeTest.h"

int main()
{
    if (!tests())
    {
        printf("Tests failed.\n");
        return 0;
    }

    Tree *tree = NULL;
    FILE *file = fopen("HW7/input.txt", "r");
    if (file == NULL || feof(file))
    {
        printf("File opening error (or the file is empty).\n");
        return 0;
    }

    if (fillTree(&tree, file) == MemoryAllocationError)
    {
        freeTree(&tree);
        printf("Memory allocation error.\n");
        return 0;
    }
    fclose(file);

    Error error = Ok;
    int result = evaluateTree(tree, &error);
    if (error != Ok){
        printf("Division by zero!\n");
        return -1;
    }

    printExpression(tree);
    printf("= %d", result);
    freeTree(&tree);
    return 0;
}