#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "States.h"
#include "List.h"

typedef struct States
{
    List **states;
    unsigned int statesCount;
} States;

typedef struct Cities
{
    unsigned int **roads;
    unsigned int citiesCount;
} Cities;

// create matrix of roads to cities and states lists
// matrix: if exists road to city it contains length of it, else - 0
// if some city contains in state - zero column to this city
// going through all states and find min way to not stated city
// add it to state list
// check for case if no roads to city exists
// print all states

void freeMatrix(unsigned int **matrix, unsigned int size)
{
    for (unsigned int i = 0; i < size; ++i)
    {
        free(matrix[i]);
    }

    free(matrix);
    matrix = NULL;
}

unsigned int** createMatrix(unsigned int size)
{
    unsigned int **matrix = calloc(size, sizeof(unsigned int*));
    if (matrix == NULL)
    {
        return NULL;
    }

    for (unsigned int i = 0; i < size; ++i)
    {
        matrix[i] = calloc(size, sizeof(unsigned int));
        if (matrix[i] == NULL)
        {
            freeMatrix(matrix, i);
            return NULL;
        }
    }

    return matrix;
}

States* createStates()
{
    return malloc(sizeof(States));
}

Cities* createCities()
{
    return malloc(sizeof(Cities));
}

void deleteStates(States **states)
{
    if (states == NULL || *states == NULL)
    {
        return;
    }
    for (int i = 0; i < (*states)->statesCount; ++i)
    {
        deleteList(&((*states)->states[i]));
    }

    free(*states);
    *states = NULL;
}

void deleteCities(Cities **cities)
{
    if (cities == NULL || *cities == NULL)
    {
        return;
    }
    freeMatrix((*cities)->roads, (*cities)->citiesCount);

    free(*cities);
    *cities = NULL;
}

Error readToMatrix(FILE *file, Cities *cities, unsigned roadsNumber)
{
    for (int i = 0; i < roadsNumber; ++i)
    {
        unsigned int firstCity = 0;

        int eofCheck = fscanf(file, "%u", &firstCity);
        if (eofCheck == EOF || eofCheck == 0)
        {
            fclose(file);
            return FileIsEmpty;
        }

        eofCheck = fgetc(file);
        if (eofCheck == EOF)
        {
            fclose(file);
            return FileIsEmpty;
        }

        unsigned int secondCity = 0;
        eofCheck = fscanf(file, "%u", &secondCity);
        if (eofCheck == EOF || eofCheck == 0)
        {
            fclose(file);
            return FileIsEmpty;
        }

        eofCheck = fgetc(file);
        if (eofCheck == EOF)
        {
            fclose(file);
            return FileIsEmpty;
        }

        unsigned int roadLength = 0;
        eofCheck = fscanf(file, "%u", &roadLength);
        if (eofCheck == EOF || eofCheck == 0)
        {
            fclose(file);
            return FileIsEmpty;
        }

        if (firstCity > cities->citiesCount || secondCity > cities->citiesCount)
        {
            fclose(file);
            return FileIsEmpty;
        }

        cities->roads[firstCity - 1][secondCity - 1] = roadLength;
    }

    return Ok;
}

Error getDataFromFile(char *fileName, Cities *cities, States *states)
{
    FILE *file = fopen(fileName, "r");
    if (file == NULL)
    {
        return FileIsNotFound;
    }

    unsigned int roadsNumber = 0;

    int eofCheck = fscanf(file, "%u %u", &cities->citiesCount, &roadsNumber);
    if (eofCheck == EOF)
    {
        fclose(file);
        return FileIsEmpty;
    }

    cities->roads = createMatrix(cities->citiesCount);
    if (cities->roads == NULL)
    {
        fclose(file);
        return MemoryAllocationError;
    }

    eofCheck = readToMatrix(file, cities, roadsNumber);
    if (eofCheck == FileIsEmpty)
    {
        return FileIsEmpty;
    }

    eofCheck = fscanf(file, "%u", &states->statesCount);
    if (eofCheck == EOF || eofCheck == 0)
    {
        fclose(file);
        return FileIsEmpty;
    }

    if (states->statesCount > cities->citiesCount)
    {
        fclose(file);
        return InvalidCitiesData;
    }

    states->states = calloc(states->statesCount, sizeof(List*));
    if (states->states == NULL)
    {
        fclose(file);
        return MemoryAllocationError;
    }

    for (int i = 0; i < states->statesCount; ++i)
    {
        unsigned int capital = 0;
        eofCheck = fscanf(file, "%u", &capital);
        if (eofCheck == EOF || eofCheck == 0)
        {
            fclose(file);
            return FileIsEmpty;
        }

        if (capital > cities->citiesCount)
        {
            fclose(file);
            return InvalidCitiesData;
        }

        eofCheck = fgetc(file);
        if (eofCheck == EOF && i != states->statesCount - 1)
        {
            return FileIsEmpty;
        }

        states->states[i] = createList();
        if (states->states[i] == NULL)
        {
            fclose(file);
            return MemoryAllocationError;
        }

        int errorCode = addValue(states->states[i], capital - 1);
        if (errorCode == 1)
        {
            fclose(file);
            return MemoryAllocationError;
        }
    }

    fclose(file);

    return Ok;
}

void zeroColumn(Cities *cities, unsigned int columnNumber)
{
    for (unsigned int i = 0; i < cities->citiesCount; ++i)
    {
        cities->roads[i][columnNumber] = 0;
    }
}

void getMinInLine(Cities *cities, unsigned value, unsigned *minLength, unsigned *minCityNumber)
{
    for (unsigned int i = 0; i < cities->citiesCount; ++i)
    {
        if (cities->roads[value][i] != 0 && cities->roads[value][i] < *minLength)
        {
            *minLength = cities->roads[value][i];
            *minCityNumber = i;
        }
    }
}

unsigned int getStateCityNumber(States *states, unsigned int stateNumber, unsigned int stateCityNumber)
{
    if (states == NULL || stateNumber > states->statesCount)
    {
        return 0;
    }

    ListElement *element = getFirstListElement(states->states[stateNumber - 1]);
    for (int i = 0; i < stateCityNumber - 1; ++i)
    {
        if (element == NULL)
        {
            return 0;
        }

        element = getNextElement(element);
    }

    ListError errorCode = 0;

    return getListElementValue(element, &errorCode) + 1;
}

Error divideCities(Cities *cities, States *states)
{
    ListError listErrorCode = ListOk;
    // zero capitals columns
    for (unsigned int i = 0; i < states->statesCount; ++i)
    {
        unsigned int city = getListElementValue(getFirstListElement(states->states[i]), &listErrorCode);
        if (listErrorCode != ListOk)
        {
            return PointerToCitiesNotFound;
        }
        zeroColumn(cities, city);
    }

    // how many free cities left
    unsigned int citiesLeft = cities->citiesCount - states->statesCount;

    while (citiesLeft != 0)
    {
        // check for case if no way to city
        bool wasAction = false;
        for (unsigned int i = 0; i < states->statesCount; ++i)
        {
            unsigned int minLength = UINT_MAX;
            unsigned int minCityNumber = UINT_MAX;

            ListElement *element = getFirstListElement(states->states[i]);

            while (element != NULL)
            {
                unsigned int value = getListElementValue(element, &listErrorCode);
                if (listErrorCode != ListOk)
                {
                    return PointerToCitiesNotFound;
                }
                getMinInLine(cities, value, &minLength, &minCityNumber);
                element = getNextElement(element);
            }

            if (minLength != UINT_MAX)
            {
                wasAction = true;
                listErrorCode = addValue(states->states[i], minCityNumber);
                if (listErrorCode == ListMemoryAllocationError)
                {
                    return MemoryAllocationError;
                }
                if (listErrorCode == ListNotFound)
                {
                    return PointerToCitiesNotFound;
                }

                --citiesLeft;
                zeroColumn(cities, minCityNumber);
            }
        }

        if (!wasAction)
        {
            return PointerToCitiesNotFound;
        }
    }
    return Ok;
}

unsigned int getRoadLength(Cities *cities, unsigned int firstCity, unsigned int secondCity)
{
    if (firstCity > cities->citiesCount || secondCity > cities->citiesCount)
    {
        return 0;
    }

    return cities->roads[firstCity - 1][secondCity - 1];
}

void printStates(States *states)
{
    if (states == NULL || states->states == NULL)
    {
        return;
    }

    ListError listErrorCode = ListOk;

    for (int i = 0; i < states->statesCount; ++i)
    {
        printf("State %u contains cities: ", i + 1);

        ListElement *element = getFirstListElement(states->states[i]);

        while (element != NULL)
        {
            unsigned int city = getListElementValue(element, &listErrorCode);
            printf("%u ", city + 1);
            element = getNextElement(element);
        }

        printf("\n");
    }
}