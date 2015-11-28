//
// Vince Allen 10/28/2015
//
// Chapter 5, Project 1
// read in average monthly rainfall for a city each month of the year
// read in actual monthly rainfall for each of the previous 12 months
// print nicely formatted table showing rainfall for each of the previous 12 month
// as well as how much above or below average the rainfall was for each month.
// to get actual rainfall for prev 12 months, program first asks for what the current
// month is and then asks for rainfall figures for the previous 12 months.
//
// the output should correctly label the months
//
// OUTPUT:
// Enter New York's average rainfall in inches for the month of
// January: 10
// February: 12
// March: 14
// April: 13
// May: 15
// June: 17
// July: 18
// August: 12
// September: 18
// October: 20
// November: 24
// December: 18
// Enter the current month (ex: January):
// May
// Enter New York's ACTUAL rainfall in inches for the month of
// May: 8
// April: 12
// March: 32
// February: 14
// January: 15
// December: 11
// November: 8
// October: 16
// September: 20
// August: 22
// July: 21
// June: 27
// Display Table or Graph? ('T' or 'G')
// G
//
// Results:
// January
// *************** 15
// ********** 10
//
// February
// ************** 14
// ************ 12
//
// March
// ******************************** 32
// ************** 14
//
// April
// ************ 12
// ************* 13
//
// May
// ******** 8
// *************** 15
//
// June
// *************************** 27
// ***************** 17
//
// July
// ********************* 21
// ****************** 18
//
// August
// ********************** 22
// ************ 12
//
// September
// ******************** 20
// ****************** 18
//
// October
// **************** 16
// ******************** 20
//
// November
// ******** 8
// ************************ 24
//
// December
// *********** 11
// ****************** 18
//
// Again (Y or n)?
//

#include <iostream>
#include <iomanip>


//#define NDEBUG
#include <assert.h>
using namespace std;

const char CITY_NAME[] = "New York";
const int TOTAL_MONTHS = 12;
const int MAX_MONTH_LABEL_LENGTH = 10;
const char MONTHS[TOTAL_MONTHS][MAX_MONTH_LABEL_LENGTH] = {
    {"January"},
    {"February"},
    {"March"},
    {"April"},
    {"May"},
    {"June"},
    {"July"},
    {"August"},
    {"September"},
    {"October"},
    {"November"},
    {"December"}
};

int getCurrentMonthIndex(char monthName[], const char months[][MAX_MONTH_LABEL_LENGTH], const int totalMonths);
void displayRainfallTable(int avgMonthyRainfall[], int actualMonthyRainfall[]);
void displayRainfallGraph(int avgMonthyRainfall[], int actualMonthyRainfall[]);

int main(int argc, const char * argv[]) {

    // ASSERTIONS

    char jan[] = "January";
    assert(getCurrentMonthIndex(jan, MONTHS, TOTAL_MONTHS) == 0);

    char dec[] = "December";
    assert(getCurrentMonthIndex(dec, MONTHS, TOTAL_MONTHS) == 11);

    //

    int avgMonthyRainfall[TOTAL_MONTHS];
    int actualMonthyRainfall[TOTAL_MONTHS];
    char currentMonth[12];

    char again = 'Y';
    while (again != 'n' && again != 'N') {

        cout << "Enter " << CITY_NAME << "'s average rainfall in inches for the month of " << endl;
        for (int i = 0; i < TOTAL_MONTHS; ++i) {
            cout << MONTHS[i] << ": ";
            cin >> avgMonthyRainfall[i];
        }

        cout << "Enter the current month (ex: January): " << endl;
        cin >> currentMonth;

        cout << "Enter " << CITY_NAME << "'s ACTUAL rainfall in inches for the month of " << endl;
        int moIndex = getCurrentMonthIndex(currentMonth, MONTHS, TOTAL_MONTHS);

        int i = 0;
        while (i > -TOTAL_MONTHS) {

            int offset = i + moIndex;
            if (i + moIndex > -1) {
                cout << MONTHS[offset] << ": ";
                cin >> actualMonthyRainfall[offset];
            } else {
                cout << MONTHS[TOTAL_MONTHS + offset] << ": ";
                cin >> actualMonthyRainfall[TOTAL_MONTHS + offset];
            }
            --i;
        }

        char displayTable;
        cout << "Display Table or Graph? ('T' or 'G')" << endl;
        cin >> displayTable;

        if (displayTable == 'T') {
            displayRainfallTable(avgMonthyRainfall, actualMonthyRainfall);
        } else {
            displayRainfallGraph(avgMonthyRainfall, actualMonthyRainfall);
        }

        cout << endl;
        cout << "Again (Y or n)?";
        cin >> again;

    }

    return 0;
}

/**
 * Returns the index of the passed month name in an array of month names.
 * @param monthName A month name ex: January
 * @param months An array of month names
 @ @param totalMonths The total number of months
 * @return An index
 */
int getCurrentMonthIndex(char monthName[], const char months[][MAX_MONTH_LABEL_LENGTH], const int totalMonths) {
    int index = -1;
    for (int i = 0; i < totalMonths; ++i) {
        if (strcmp(monthName, months[i]) == 0) {
            index = i;
            break;
        }
    }
    return index;
}

/**
 * Renders a table comparing average monthly rainfall to actual rainfall.
 * @param avgMonthyRainfall An array representing average monthly rainfall.
 * @param actualMonthyRainfall An array representing actual monthly rainfall.
 */
void displayRainfallTable(int avgMonthyRainfall[], int actualMonthyRainfall[]) {
    cout << endl;
    cout << "Results: " << endl;
    for (int i = 0; i < TOTAL_MONTHS; ++i) {

        int actualRainfall = actualMonthyRainfall[i];
        int diff = actualRainfall - avgMonthyRainfall[i];
        char sign = diff > 0 ? '+' : ' ';

        cout << left << setw(MAX_MONTH_LABEL_LENGTH) << setfill(' ') << MONTHS[i] << actualRainfall << " in. " << sign << diff << " avg" << endl;
    }
}

/**
 * Renders a graph comparing average monthly rainfall to actual rainfall.
 * @param avgMonthyRainfall An array representing average monthly rainfall.
 * @param actualMonthyRainfall An array representing actual monthly rainfall.
 */
void displayRainfallGraph(int avgMonthyRainfall[], int actualMonthyRainfall[]) {
    cout << endl;
    cout << "Results: " << endl;
    for (int i = 0; i < TOTAL_MONTHS; ++i) {

        int actualRainfall = actualMonthyRainfall[i];
        int avgRainfall = avgMonthyRainfall[i];

        cout << MONTHS[i] << endl;
        cout << left << setw(actualRainfall) << setfill('*') << "" << " " << actualRainfall << endl;
        cout << left << setw(avgRainfall) << setfill('*') << "" << " " << avgRainfall << endl;
        cout << endl;
    }

}

