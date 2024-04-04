#include <stdio.h>
#include "OperationTree.c"
#include "OperationTreeTest.c"

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

    const char *fileName = "HW7/input.txt";
    Tree *tree = NULL;
    Error error = fillTree(&tree, fileName);
    if (error != Ok)
    {
        printErrors(error);
        freeTree(&tree);
        return error;
    }

    int result = evaluateTree(tree, &error);
    if (error != Ok)
    {
        printErrors(error);
        return error;
    }

    printExpression(tree);
    printf("= %d", result);
    freeTree(&tree);
    return 0;
}