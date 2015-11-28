//
//  Vince Allen
//  Chapter 7, Project4
//
//  You operate several hotdog stands. Define a class called HotDogStand that has a
//  member variable for the hot dog stands's ID number and a member variable for how
//  many hot dogs the stand sold that day. Create a constructor that allows a user of
//  the class to initialize both values.
//
//  Also create a function name JustSold to increment the number of hot dogs sold. Add
//  another function to return the number of hotdogs sold.
//
//  Add a static variable that tracks the total number of hot dogs sold by all stands.
//  Add a static function to return the value.
//
//  Write a main function that tests your class w at least 3 stands selling a variety of hot dogs.
//
//  OUTPUT:
//
//  [PASSED] Constructor should allow user to initialize both values.
//  [PASSED] Constructor should allow user to initialize only first value.
//  [PASSED] Constructor should allow user to initialize using default values.
//  [PASSED] Should track the total number of hot dogs sold by a specific stand.
//  [PASSED] Should track the total number of hot dogs sold by all stands.
//
//  All tests succeeded.
//

#include <iostream>
#include "TestRunner.h"
#include "HotDogStand.h"

bool HDStandTest0();
bool HDStandTest1();
bool HDStandTest2();
bool HDStandTest3();
bool HDStandTest4();

int HotDogStand::totalSales = 0;

int main(int argc, const char * argv[]) {

    const int TOTAL_TESTS = 5;

    Test HDStandTests[TOTAL_TESTS];

    strcpy(HDStandTests[0].description, "Constructor should allow user to initialize both values.");
    strcpy(HDStandTests[1].description, "Constructor should allow user to initialize only first value.");
    strcpy(HDStandTests[2].description, "Constructor should allow user to initialize using default values.");
    strcpy(HDStandTests[3].description, "Should track the total number of hot dogs sold by a specific stand.");
    strcpy(HDStandTests[4].description, "Should track the total number of hot dogs sold by all stands.");

    HDStandTests[0].func = HDStandTest0;
    HDStandTests[1].func = HDStandTest1;
    HDStandTests[2].func = HDStandTest2;
    HDStandTests[3].func = HDStandTest3;
    HDStandTests[4].func = HDStandTest4;

    //

    TestRunner::runTests(HDStandTests, TOTAL_TESTS);

    std::cout << std::endl << "All tests succeeded." << std::endl << std::endl;
    
    return 0;
}

bool HDStandTest0() {
    char id[7] = "000000";
    HotDogStand standA(id, 20);
    const char *expectedID = &id[0];
    const char *returnedID = standA.getID();
    int cmpResult = std::strcmp(expectedID, returnedID);
    return cmpResult == 0 && standA.getDailySales() == 20;
};

bool HDStandTest1() {
    char id[7] = "000000";
    HotDogStand standA(id);
    const char *expectedID = &id[0];
    const char *returnedID = standA.getID();
    int cmpResult = std::strcmp(expectedID, returnedID);
    return cmpResult == 0 && standA.getDailySales() == 0;
};

bool HDStandTest2() {
    char id[7] = "000000";
    HotDogStand standA;
    const char *expectedID = &id[0];
    const char *returnedID = standA.getID();
    int cmpResult = std::strcmp(expectedID, returnedID);
    return cmpResult == 0 && standA.getDailySales() == 0;
};

bool HDStandTest3() {
    HotDogStand standA;
    standA.justSold();
    standA.justSold();
    standA.justSold();
    
    return standA.getDailySales() == 3;
};

bool HDStandTest4() {
    HotDogStand standA;
    standA.justSold();
    standA.justSold();
    standA.justSold();

    HotDogStand standB;
    standB.justSold();
    standB.justSold();

    HotDogStand standC;
    standC.justSold();

    return HotDogStand::getTotalSales() == 9;
};