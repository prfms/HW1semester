#ifndef HOMEWORKS1SEMESTER_MERGELISTTEST_H
#define HOMEWORKS1SEMESTER_MERGELISTTEST_H
#include "mergeList.h"

// заполнение списка значениями из файла
Error fillList(List **head, const char * const pathToFile);

// тестирование addRecord и mergeSort
bool tests();

#endif //HOMEWORKS1SEMESTER_MERGELISTTEST_H
