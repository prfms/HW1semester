#include <stdio.h>
#include "OperationTree.h"
#include "OperationTreeTest.h"

void printErrors(Error errorCode)
{
    switch (errorCode)
    {
        case Ok:
            break;
        case MemoryAllocationError:
            printf("Memory allocation error!\n");
            break;
        case  FileOpeningError:
            printf("File opening error!\n");
            break;
        case TestsFailed:
            printf("Tests have failed!\n");
            break;
        case DivisionByZero:
            printf("Division by zero!\n");
            break;
    }
}

int main()
{
    if (!tests())
    {
        printErrors(TestsFailed);
        return TestsFailed;
    }

    FILE *file = fopen("HW7/input.txt", "r");
    Tree *tree = NULL;
    Error error = fillTree(&tree, file);
    if (error != Ok)
    {
        printErrors(error);
        freeTree(&tree);
        fclose(file);
        return error;
    }
    fclose(file);
    int result = evaluateTree(tree, &error);
    if (error != Ok)
    {
        printErrors(error);
        fclose(file);
        return error;
    }

    printExpression(tree);
    printf("= %d", result);
    freeTree(&tree);
    return 0;
}