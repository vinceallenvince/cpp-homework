//
// Vince Allen
// Chapter 6, project3
//
// Write a definition of a class named Point that might be used to store and
// manipulate the location of a point on a plane. Declare the following member functions:
//
// 1. a member function set that sets the private data after an object of this class has been created.
// 2. a member function to move the point by an amount along the vertical and horizontal directions
//    specified by the first and second arguments.
// 3. a member function to rotate the point by 90 degrees clockwise around the origin.
// 4. two const inspector functions to retrieve the current coordinates of the point.
//
// Comment the functions. Embed the class in a test program that requests data for several points
// from the user, creates the points, and exercises the member functions.
//
// OUTPUT:
//
// Set the x coordinate:
// 6531
// Set the y coordinate:
// -88822
// Enter an amount to move the x coordinate:
// 3257
// Enter an amount to move the y coordinate:
// -432111
//
// [PASSED] Should set initial data.
// [PASSED] Should move point to a new location.
// [PASSED] Should rotate point 90 degrees around the origin.
//
// All tests succeeded.
//
// Again (Y or n)?
//

#include <iostream>
#include <cmath>
#include "assert.h"
using namespace::std;

class Point {
    double x;
    double y;
public:
    void setData(double x, double y) { this->x = x; this->y = y; };
    const double getX() { return x; };
    const double getY() { return y; };
    void move(double x, double y);
    void rotate90();
};

double xRotate90(double x, double y);
double yRotate90(double x, double y);

int main(int argc, const char * argv[]) {

    char again = 'Y';
    Point point;
    int x, y, moveX, moveY;

    while (again != 'n' && again != 'N') {

        cout << "Set the x coordinate: " << endl;
        cin >> x;

        cout << "Set the y coordinate: " << endl;
        cin >> y;

        cout << "Enter an amount to move the x coordinate: " << endl;
        cin >> moveX;

        cout << "Enter an amount to move the y coordinate: " << endl;
        cin >> moveY;
        cout << endl;

        char test1[256] = "Should set initial data.";
        point.setData(x, y);
        assert(point.getX() == x);
        assert(point.getY() == y);
        cout << "[PASSED] " << test1 << endl;

        char test2[256] = "Should move point to a new location.";
        point.setData(x, y);
        point.move(moveX, moveY);
        assert(point.getX() == x + moveX);
        assert(point.getY() == y + moveY);
        cout << "[PASSED] " << test2 << endl;

        char test3[256] = "Should rotate point 90 degrees around the origin.";
        point.setData(x, y);
        point.rotate90();
        assert(point.getX() == xRotate90(x, y));
        assert(point.getY() == yRotate90(x, y));
        cout << "[PASSED] " << test3 << endl;

        cout << endl << "All tests succeeded." << endl << endl;

        std::cout << "Again (Y or n)? ";
        std::cin >> again;
    }

    return 0;
}

double xRotate90(double x, double y) {
    double radians = (90 * M_PI) / 180 ;
    double c = cos(radians);
    double s = sin(radians);
    return x * c - y * s;
}

double yRotate90(double x, double y) {
    double radians = (90 * M_PI) / 180 ;
    double c = cos(radians);
    double s = sin(radians);
    x = x * c - y * s;
    return x * s + y * c;
}

/**
 * Moves the point to a new location.
 * int x The location on the x-axis.
 * int y The location on the y-axis.
 */
void Point::move(double x, double y) {
    this->x += x;
    this->y += y;
};

/**
 * Rotates the point 90 degrees around the origin.
 */
void Point::rotate90() {
    double radians = (90 * M_PI) / 180;
    double c = cos(radians);
    double s = sin(radians);
    this->x = this->x * c - this->y * s;
    this->y = this->x * s + this->y * c;
};
