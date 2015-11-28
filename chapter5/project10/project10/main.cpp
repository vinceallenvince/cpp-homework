//
// Vince Allen 10/28/2015
//
// Chapter 5, Project 10
//
// Write a program to assign passenger seats on an airplane. Assume a small place with
// seat numbering as follows.
//
// 1   A B  C D
// 2   A B  C D
// 3   A B  C D
// 4   A B  C D
// 5   A B  C D
// 6   A B  C D
// 7   A B  C D
//
// The program should display the seat pattern w an 'X' marking the seats already assigned.
//
// After displaying the seats available, the program prompts for the seat desired, the user
// enters a seat, and the display updates. This continues until all the seats are filled or
// the user signals the program should end.
//
// If the user enters a seat that is already occupied, the program should prompt the user
// to make another selection.
//
// OUTPUT:
//
// Current seating chart:
//
// 0   A B  C X
// 1   A X  C D
// 2   X B  C D
// 3   A B  C D
// 4   A B  C D
// 5   A X  C D
// 6   A B  C D
//
// Please pick a row. (ex: 3)
// 2
// Please pick a seat. (ex: C)
// B
//
// Current seating chart:
//
// 0   A B  C X
// 1   A X  C D
// 2   X X  C D
// 3   A B  C D
// 4   A B  C D
// 5   A X  C D
// 6   A B  C D

// Again (Y or n) Y
// Please pick a row. (ex: 3)
// 5B
// Please pick a seat. (ex: C)
//
// Seat 5B is taken. Please chose again.
//
// Current seating chart:
//
// 0   A B  C X
// 1   A X  C D
// 2   X X  C D
// 3   A B  C D
// 4   A B  C D
// 5   A X  C D
// 6   A B  C D

// Please pick a row. (ex: 3)
//

#include <iostream>
#include <iomanip>
using namespace std;

//#define NDEBUG
#include <assert.h>

const int TOTAL_ROWS = 7;
const int TOTAL_COLS = 4;
const int TOTAL_SEATS = TOTAL_ROWS * TOTAL_COLS;
char COL_NAMES[] = {'A', 'B', 'C', 'D'};

void initializeSeats(int seats[][TOTAL_COLS], int totalRows, int totalCols, int seatsOccupied[], int totalSeatsOccupied);
void initializeOccupiedSeats(int seatsOccupied[], int totalSeats, int totalSeatsOccupied);
bool seatOccupied(int index, int seatsOccupied[], int totalSeatsOccupied);
void displaySeatingChart(int seats[][TOTAL_COLS], int totalRows, int totalCols, const char colNames[]);
int seatIndexFromInput(char chosenSeat[], char colNames[], int totalCols);
void occupySeat(int seatIndex, int seatsOccupied[], int &totalSeatsOccupied);

int main(int argc, const char * argv[]) {

    // ASSERTIONS
    int tempSeatsOccupied[] = {7, 22, 21, 10};
    int tempTotalSeatsOccupied = 4;
    assert(seatOccupied(7, tempSeatsOccupied, tempTotalSeatsOccupied));
    assert(seatOccupied(22, tempSeatsOccupied, tempTotalSeatsOccupied));
    assert(seatOccupied(21, tempSeatsOccupied, tempTotalSeatsOccupied));
    assert(seatOccupied(10, tempSeatsOccupied, tempTotalSeatsOccupied));

    occupySeat(1, tempSeatsOccupied, tempTotalSeatsOccupied);
    assert(tempTotalSeatsOccupied == 5);

    char tempChosenSeat[] = {'2', 'C'};
    assert(seatIndexFromInput(tempChosenSeat, COL_NAMES, TOTAL_COLS) == 10);

    //

    srand(99);

    int seats[TOTAL_ROWS][TOTAL_COLS];
    int seatsOccupied[TOTAL_SEATS];
    int totalSeatsOccupied = 4;
    char chosenSeat[2];

    initializeOccupiedSeats(seatsOccupied, totalSeatsOccupied, TOTAL_SEATS);
    initializeSeats(seats, TOTAL_ROWS, TOTAL_COLS, seatsOccupied, totalSeatsOccupied);
    displaySeatingChart(seats, TOTAL_ROWS, TOTAL_COLS, COL_NAMES);

    char again = 'Y';
    while (again != 'n' && again != 'N') {

        cout << "Please pick a row. (ex: 3)" << endl;
        cin >> chosenSeat[0];

        cout << "Please pick a seat. (ex: C)" << endl;
        cin >> chosenSeat[1];

        int seatIndex = seatIndexFromInput(chosenSeat, COL_NAMES, TOTAL_COLS);

        if (!seatOccupied(seatIndex, seatsOccupied, TOTAL_SEATS)) {
            occupySeat(seatIndex, seatsOccupied, totalSeatsOccupied);
            initializeSeats(seats, TOTAL_ROWS, TOTAL_COLS, seatsOccupied, totalSeatsOccupied);
            displaySeatingChart(seats, TOTAL_ROWS, TOTAL_COLS, COL_NAMES);

            cout << "Again (Y or n) ";
            cin >> again;

        } else {
            cout << endl << "Seat " << chosenSeat[0] << chosenSeat[1] << " is taken. Please chose again." << endl;
            displaySeatingChart(seats, TOTAL_ROWS, TOTAL_COLS, COL_NAMES);
        }
    }

    return 0;
}

/**
 * Updates the seats array with occupied seats. Each index in the seats array represents a seat in the
 * row x col matix of seats. If the value at an index is 0, the seat in not taken. If the value is 1,
 * the seat is occupied.
 * @param seats[][] A two-dimensional array representing the row x col seating matrix
 * @param totalRows The total rows in the seating matrix
 * @param totalCols The total columns in the seating matrix
 * @param seatsOccupied[] An array of indexes in the seating matrix representing occupied seats
 * @param totalSeatsOccupied The number of occupied seats
 */
void initializeSeats(int seats[][TOTAL_COLS], int totalRows, int totalCols, int seatsOccupied[], int totalSeatsOccupied) {
    int *ptr = &seats[0][0];
    for (int y = 0; y < totalRows; y++) {
        for (int x = 0; x < totalCols; x++) {
            int seatIndex = (totalCols * y) + x;
            int seatVal = 0;
            if (seatOccupied(seatIndex, seatsOccupied, totalSeatsOccupied)) {
                seatVal = 1;
            }
            *ptr++ = seatVal;
        }
    }
}

/**
 * Randomly selects a unqiue set of seats in the seating matrix to occupy.
 * @param seatsOccupied[] An array of indexes in the seating matrix representing occupied seats
 * @param totalSeats The total seats to occupy
 * @param totalSeatsOccupied The number of occupied seats
 */
void initializeOccupiedSeats(int seatsOccupied[], int totalSeats, int totalSeatsOccupied) {
    int *ptr = &seatsOccupied[0];
    int totalSeatsTaken = 0;
    while (totalSeatsTaken < totalSeats) {
        int randNum = rand() % totalSeatsOccupied;
        if (!seatOccupied(randNum, seatsOccupied, totalSeats)) {
            *ptr++ = randNum;
            totalSeatsTaken++;
        }
    }
}

/**
 * Checks if a seat in the seating matrix is occupied.
 * @param index An index representing a seat in the matrix
 * @param seatsOccupied[] An array of indexes in the seating matrix representing occupied seats
 * @param totalSeatsOccupied The number of occupied seats
 */
bool seatOccupied(int index, int seatsOccupied[], int totalSeatsOccupied) {
    int *ptr = &seatsOccupied[0];
    for (int i = 0; i < totalSeatsOccupied; ++i) {
        int seatNum = *ptr++;
        if (index == seatNum) {
            return true;
        }
    }
    return false;
}

/**
 * Renders the seating chart.
 * @param seats[][] A two-dimensional array representing the row x col seating matrix
 * @param totalRows The total rows in the seating matrix
 * @param totalCols The total columns in the seating matrix
 * @param colNames[] An array of column names
 */
void displaySeatingChart(int seats[][TOTAL_COLS], int totalRows, int totalCols, const char colNames[]) {
    cout << endl << "Current seating chart:" << endl << endl;
    int *ptr = &seats[0][0];
    for (int y = 0; y < totalRows; y++) { // total rows
        cout << left << setw(4) << setfill(' ') << y;
        for (int x = 0; x < totalCols; x++) { // total cols
            int seatVal = *ptr++;
            char seatCol =  seatVal == 1 ? 'X' : colNames[x];
            cout << seatCol << ' ';
            if (x == 1) cout << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

/**
 * Returns an index representing a seat in the matrix.
 * @param chosenSeat[] A pair of characters representing a seat in the matrix.
 * @param colNames[] An array of column names
 * @param totalCols The total number of columns
 */
int seatIndexFromInput(char chosenSeat[], char colNames[], int totalCols) {
    int colIndex = -1;
    char *ptr = &colNames[0];
    for (int i = 0; i < totalCols; ++i) {
        if (chosenSeat[1] == *ptr++) {
            colIndex = i;
            break;
        }
    }
    int rowIndex = chosenSeat[0] - '0';
    return (rowIndex * totalCols) + colIndex;
}

/**
 * Occupies a seat in the matrix.
 * @param seatIndex An index representing a seat in the matrix
 * @param seatsOccupied[] An array of indexes in the seating matrix representing occupied seats
 * @param totalSeatsOccupied The number of occupied seats
 */
void occupySeat(int seatIndex, int seatsOccupied[], int &totalSeatsOccupied) {
    seatsOccupied[totalSeatsOccupied] = seatIndex;
    totalSeatsOccupied++;
}
