#ifndef HOMEWORKS_BINARYNUMBER_H
#define HOMEWORKS_BINARYNUMBER_H

#define LENGTH_BINARY_NUMBER sizeof(int) * 8
#include <stdbool.h>

// ������������� ����������� ����� � �������� ������� ���������
void binaryRepresent(bool array[], int number);

// �������� ���� �������� �����, ��������� - �������� �����
void addBinaryNumbers(bool firstNumber[], bool secondNumber[], bool answer[]);

// ������������� ��������� ����� � ���������� ������� ���������
int convertFromBinaryToDecimal(bool array[], char length);

// ����� �������
void printArray(bool array[], char length);

#endif //HOMEWORKS_BINARYNUMBER_H