//
//  Month.cpp
//  Chapter 7, Project1
//

#include <iostream>
#include "Month.h"

const int SHORT_NAME_LENGTH = 3;

Month::Month(char firstChar, char secondChar, char thirdChar) {
    int nameLength = SHORT_NAME_LENGTH;
    char name[SHORT_NAME_LENGTH] = {firstChar, secondChar, thirdChar};
    this->setMonthIndex(this->getMonthIndexByShortName(name, nameLength));
};

Month::Month(int monthIndex) {
    this->setMonthIndex(monthIndex);
};

int Month::getMonthIndexByShortName(char *name, int nameLength) {

    char *ptr_name = &name[0];
    const char *ptr_nameShort = &this->monthNamesShort[0][0];

    for (int i = 0; i < this->totalMonths; ++i) {
        for (int j = 0; j < nameLength; ++j) {

            char letterShort = *ptr_nameShort;
            char letterName = *ptr_name;

            if (letterShort == letterName && j == nameLength - 1) {
                return i;
            } else if (letterShort == letterName) {
                ptr_nameShort++;
                ptr_name++;
                continue;
            } else {
                ptr_nameShort += nameLength - j + 1;
                ptr_name -= j;
                break;
            }
        }
    }
    return 0;
};

void Month::setMonthByFirstThreeChars(char firstChar, char secondChar, char thirdChar) {
    int nameLength = SHORT_NAME_LENGTH;
    char name[SHORT_NAME_LENGTH] = {firstChar, secondChar, thirdChar};
    this->setMonthIndex(this->getMonthIndexByShortName(name, nameLength));
};

const char* Month::getMonthAsFirstThreeChars() {
    const char *ptr_shortName = &this->monthNamesShort[this->getMonthIndex()][0];
    return ptr_shortName;
};

Month Month::getNextMonth() {
    int currentMonthIndex = this->getMonthIndex();
    int nextMonthIndex = currentMonthIndex == 11 ? 0 : currentMonthIndex + 1;
    Month month(nextMonthIndex);
    return month;
};
