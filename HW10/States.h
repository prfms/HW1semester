#ifndef HOMEWORKS1SEMESTER_STATES_H
#define HOMEWORKS1SEMESTER_STATES_H

#include <stdbool.h>

typedef enum
{
    InvalidCitiesData = -3,
    FileIsNotFound = -2,
    ListIsNotFound = -1,
    Ok = 0,
    MemoryAllocationError = 1,
    FileIsEmpty = 2,
    ElementIsNotFound = 3,
    PointerToCitiesNotFound = 4,
    TestsFailed = -100
} Error;

typedef struct Cities Cities;

typedef struct States States;

// allocate memory for State
States* createStates();

// allocate memory for Cities
Cities* createCities();

// get data from file and create roads between cities and create states with only capitals
// return 2 if not enough data in the file
// return 1 if not enough memory
// return 0 if everything is ok
// return -1 if no file with this name
// return -2 if city has number more than cities count
// return -3 if states count more than cities count
Error getDataFromFile(char *fileName, Cities *cities, States *states);

// divide cities between states
// return 0 if all is ok
// return 1 if pointer to cities or states don't exist
// return -1 if no roads to city
Error divideCities(Cities *cities, States *states);

// print all states and cities in its own
void printStates(States *states);

// delete states and clear memory
void deleteStates(States **states);

// delete road and clear memory
void deleteCities(Cities **cities);

// return length of road between two cities
unsigned int getRoadLength(Cities *cities, unsigned int firstCity, unsigned int secondCity);

// get number of nth state state's city
unsigned int getStateCityNumber(States *states, unsigned int stateNumber, unsigned int stateCityNumber);

#endif //HOMEWORKS1SEMESTER_STATES_H
