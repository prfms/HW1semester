#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "AVLTreeTest.h"

bool testGetValue()
{
    Tree *testTree = calloc(1, sizeof(Tree));
    if (testTree == NULL)
    {
        return false;
    }
    testTree->value = calloc(2, sizeof(char));
    if (testTree->value == NULL)
    {
        free(testTree);
        return false;
    }
    testTree->key = calloc(2, sizeof(char));
    if (testTree->key == NULL)
    {
        free(testTree);
        return false;
    }
    strcpy(testTree->key, "C");
    strcpy(testTree->value, "C");

    testTree->leftChild = calloc(1, sizeof(Tree));
    if (testTree->leftChild == NULL)
    {
        freeNode(testTree);
        return false;
    }
    testTree->leftChild->value = calloc(2, sizeof(char));
    if (testTree->leftChild->value == NULL)
    {
        freeTree(testTree);
        return false;
    }
    testTree->leftChild->key = calloc(2, sizeof(char));
    if (testTree->leftChild->key == NULL)
    {
        freeTree(testTree);
        return false;
    }
    strcpy(testTree->leftChild->key, "A");
    strcpy(testTree->leftChild->value, "A");

    bool resultTest = strcmp(getValue(testTree, "A"), "A") == 0;
    freeTree(testTree);
    return resultTest;
}

bool testAdd()
{
    Tree *testTree = NULL;
    Error errorCode = Ok;
    testTree = addValue(testTree, "5", "5", &errorCode);
    if (errorCode != Ok)
    {
        freeTree(testTree);
        return false;
    }
    testTree = addValue(testTree, "3", "3", &errorCode);
    if (errorCode != Ok)
    {
        freeTree(testTree);
        return false;
    }
    testTree = addValue(testTree, "7", "7", &errorCode);
    if (errorCode != Ok)
    {
        freeTree(testTree);
        return false;
    }

    bool firstTest = strcmp(getValue(testTree, "5"), "5") == 0;
    bool secondTest = strcmp(getValue(testTree, "3"), "3") == 0;
    bool thirdTest = strcmp(getValue(testTree, "7"), "7") == 0;
    freeTree(testTree);

    return firstTest && secondTest && thirdTest;
}

bool testDelete()
{
    Tree *testTree = NULL;
    Error errorCode = Ok;
    testTree = addValue(testTree, "5", "5", &errorCode);
    if (errorCode != Ok)
    {
        freeTree(testTree);
        return false;
    }
    testTree = addValue(testTree, "3", "3", &errorCode);
    if (errorCode != Ok)
    {
        freeTree(testTree);
        return false;
    }
    testTree = addValue(testTree, "7", "7", &errorCode);
    if (errorCode != Ok)
    {
        freeTree(testTree);
        return false;
    }

    deleteElement(testTree, "5");
    bool firstTest = getValue(testTree, "5") == NULL;
    bool secondTest = strcmp(getValue(testTree, "3"), "3") == 0;
    bool thirdTest = strcmp(getValue(testTree, "7"), "7") == 0;
    freeTree(testTree);

    return firstTest && secondTest && thirdTest;
}

int checkBalancedTree(Tree *tree, bool *isBalanced)
{
    if (tree == NULL)
    {
        return 0;
    }
    int heightLeftChild = checkBalancedTree(tree->leftChild, isBalanced);
    int heightRightChild = checkBalancedTree(tree->rightChild, isBalanced);

    if (tree->balance != (heightRightChild - heightLeftChild))
    {
        *isBalanced = false;
    }

    return (heightLeftChild > heightRightChild ? heightLeftChild : heightRightChild) + 1;
}

bool testBalancedTree()
{
    Tree *testTree = NULL;
    Error errorCode = Ok;
    bool resultTest = true;
    testTree = addValue(testTree, "5", "5", &errorCode);
    if (errorCode != Ok)
    {
        freeTree(testTree);
        return false;
    }
    testTree = addValue(testTree, "2", "2", &errorCode);
    if (errorCode != Ok)
    {
        freeTree(testTree);
        return false;
    }
    testTree = addValue(testTree, "8", "8", &errorCode);
    if (errorCode != Ok)
    {
        freeTree(testTree);
        return false;
    }
    testTree = addValue(testTree, "1", "1", &errorCode);
    if (errorCode != Ok)
    {
        freeTree(testTree);
        return false;
    }
    testTree = addValue(testTree, "3", "3", &errorCode);
    if (errorCode != Ok)
    {
        freeTree(testTree);
        return false;
    }
    checkBalancedTree(testTree, &resultTest);

    testTree = addValue(testTree, "4", "4", &errorCode);
    if (errorCode != Ok)
    {
        freeTree(testTree);
        return false;
    }
    checkBalancedTree(testTree, &resultTest);

    testTree = deleteElement(testTree, "5");
    checkBalancedTree(testTree, &resultTest);

    freeTree(testTree);
    return resultTest;
}

bool tests()
{
    return testGetValue() && testAdd() && testDelete() && testBalancedTree();
}