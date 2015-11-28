//
//  Month.h
//  Chapter 7, Project1
//

#ifndef __project1__Month__
#define __project1__Month__

#include <stdio.h>

class Month {

    int monthIndex;
    const int totalMonths = 12;
    const int longNameLength = 10;
    const int shortNameLength = 4;
    const char monthNamesLong[12][10] = {
        "january",
        "february",
        "march",
        "april",
        "may",
        "june",
        "july",
        "august",
        "september",
        "october",
        "november",
        "december"
    };
    const char monthNamesShort[12][4] = {
        "jan",
        "feb",
        "mar",
        "apr",
        "may",
        "jun",
        "jul",
        "aug",
        "sep",
        "oct",
        "nov",
        "dec"
    };

    int getMonthIndexByShortName(char *name, int nameLength);
    int getMonthIndexByLongName(char *name);

public:

    Month(char firstChar, char secondChar, char thirdChar);
    Month(int monthIndex = 0);

    void setMonthIndex(int monthIndex) { this->monthIndex = monthIndex; };
    int getMonthIndex() { return this->monthIndex; };

    void setMonthByFirstThreeChars(char firstChar, char secondChar, char thirdChar);
    const char* getMonthAsFirstThreeChars();

    Month getNextMonth();

};

#endif /* defined(__project1__Month__) */
