#ifndef HOMEWORKS_BINARYNUMBER_H
#define HOMEWORKS_BINARYNUMBER_H
#define lengthBinaryNumber sizeof(int) * 8
// ������������� ����������� ����� � �������� ������� ���������
void binaryRepresentation(unsigned char array[], int number);
// �������� ���� �������� �����, ��������� - �������� �����
void addBinaryNumbers(unsigned char firstNumber[], unsigned char secondNumber[], unsigned char answer[]);
// ������������� ��������� ����� � ���������� ������� ���������
int conversionFromBinaryToDecimal(unsigned char array[], char length);
// ����� �������
void printArray(unsigned char array[], char length);
// ��� ������:
// -1 - �������� ����������� � �������� �����
// -2 - �������� �������� �������� �����
// -3 - �������� ����������� � ���������� �����
int testBinaryNumber();
#endif //HOMEWORKS_BINARYNUMBER_H