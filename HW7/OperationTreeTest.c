#include "OperationTree.h"
#include <stdio.h>
#include <stdbool.h>

bool testMultiplyAndAdd()
{
    char tests[] = "(* (+ -10 -2) 3)";
    Tree *tree = NULL;
    FILE *fileOut = fopen("test.txt", "w");
    if (fileOut == NULL)
    {
        printf("File opening error.\n");
        return false;
    }
    fprintf(fileOut, "%s", tests);
    fclose(fileOut);

    FILE *fileIn = fopen("test.txt", "r");
    if (fileIn == NULL)
    {
        printf("File opening error.\n");
        return false;
    }

    if (fillTree(&tree, fileIn) == MemoryAllocationError)
    {
        fclose(fileIn);
        freeTree(&tree);
        printf("Memory allocation error.\n");
        return false;
    }
    fclose(fileIn);

    Error error = Ok;
    int answer = evaluateTree(tree, &error);
    freeTree(&tree);
    return answer == -36 && error == Ok;
}

bool testAllOperations()
{
    char tests[] = "(/ (* 5 10) (+ (- 10 3) (* 1 3)))";
    Tree *tree = NULL;
    FILE *fileOut = fopen("test.txt", "w");
    if (fileOut == NULL)
    {
        printf("File opening error.\n");
        return false;
    }
    fprintf(fileOut, "%s", tests);
    fclose(fileOut);

    FILE *fileIn = fopen("test.txt", "r");
    if (fileIn == NULL)
    {
        printf("File opening error.\n");
        return false;
    }

    if (fillTree(&tree, fileIn) == MemoryAllocationError)
    {
        fclose(fileIn);
        freeTree(&tree);
        printf("Memory allocation error.\n");
        return 0;
    }
    fclose(fileIn);

    Error error = Ok;
    int answer = evaluateTree(tree, &error);
    freeTree(&tree);
    return answer == 5 && error == Ok;
}

bool tests()
{
    return testMultiplyAndAdd() && testAllOperations();
}
