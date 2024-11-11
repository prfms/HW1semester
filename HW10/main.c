#include <stdio.h>

#include "States.h"
#include "StatesTest.h"

int main()
{
    if (!statesTest()) {
        printf("Tests Failed");
        return TestsFailed;
    }

    Cities *cities = createCities();
    if (cities == NULL)
    {
        printf("Not enough memory");
        return MemoryAllocationError;
    }

    States *states = createStates();
    if (states == NULL)
    {
        printf("Not enough memory");
        deleteCities(&cities);
        return MemoryAllocationError;
    }

    printf("Input file name with length less than 20 symbols: ");
    char fileName[20] = {0};
    scanf("%s", fileName);

    Error errorCode = getDataFromFile(fileName, cities, states);
    if (errorCode != Ok)
    {
        deleteCities(&cities);
        deleteStates(&states);
        return errorCode;
    }

    errorCode = divideCities(cities, states);
    if (errorCode == PointerToCitiesNotFound)
    {
        printf("Some city doesn't have roads");
        deleteCities(&cities);
        deleteStates(&states);
        return InvalidCitiesData;
    }
    if (errorCode == MemoryAllocationError)
    {
        printf("Memory allocation error occurred");
        deleteCities(&cities);
        deleteStates(&states);
        return MemoryAllocationError;
    }

    printStates(states);

    deleteCities(&cities);
    deleteStates(&states);

    return 0;
}