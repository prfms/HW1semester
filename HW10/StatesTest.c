#include "StatesTest.h"

bool getDataFromFileAndGetRoadLengthTest()
{
    Cities *cities = createCities();
    if (cities == NULL)
    {
        return false;
    }

    States *states = createStates();
    if (states == NULL)
    {
        deleteCities(&cities);
        return false;
    }

    int errorCode = getDataFromFile("HW10/data.txt", cities, states);
    if (errorCode)
    {
        deleteCities(&cities);
        deleteStates(&states);
        return false;
    }

    bool test1 = getRoadLength(cities, 1, 2) == 2;
    bool test2 = getRoadLength(cities, 1, 3) == 3;
    bool test3 = getRoadLength(cities, 2, 5) == 4;
    bool test4 = getRoadLength(cities, 2, 6) == 5;
    bool test5 = getRoadLength(cities, 3, 4) == 6;
    bool test6 = getRoadLength(cities, 4, 1) == 7;
    bool test7 = getRoadLength(cities, 5, 2) == 8;
    bool test8 = getRoadLength(cities, 3, 1) == 9;
    bool test9 = getStateCityNumber(states, 1, 1) == 1;
    bool test10 = getStateCityNumber(states, 2, 1) == 2;

    deleteCities(&cities);
    deleteStates(&states);

    return test1 && test2 && test3 && test4 && test5
           && test6 && test7 && test8 && test9 && test10;
}

bool divideCitiesAndGetStateCityNumberTest() {
    Cities *cities = createCities();
    if (cities == NULL) {
        return false;
    }

    States *states = createStates();
    if (states == NULL) {
        deleteCities(&cities);
        return false;
    }

    int errorCode = getDataFromFile("HwW10/data.txt", cities, states);
    if (errorCode) {
        deleteCities(&cities);
        deleteStates(&states);
        return false;
    }

    divideCities(cities, states);

    bool test1 = getStateCityNumber(states, 1, 1) == 4;
    bool test2 = getStateCityNumber(states, 1, 2) == 3;
    bool test3 = getStateCityNumber(states, 1, 3) == 1;
    bool test4 = getStateCityNumber(states, 2, 1) == 6;
    bool test5 = getStateCityNumber(states, 2, 2) == 5;
    bool test6 = getStateCityNumber(states, 2, 3) == 2;

    deleteCities(&cities);
    deleteStates(&states);

    return test1 && test2 && test3
           && test4 && test5 && test6;
}

bool statesTest() {
    return getDataFromFileAndGetRoadLengthTest() && divideCitiesAndGetStateCityNumberTest();
}