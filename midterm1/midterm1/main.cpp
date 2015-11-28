//
//  Vince Allen
//  Midterm, Project 1A
//
//  The program should create a Point P1 at X=3, Y=4;
//  The program should output Radius of P1
//  The program should scale point P1 by 5
//  The program should output the Radius of scaled P1
//
//  OUTPUT:
//
//  Radius of P1: 5
//  Radius of scaled P1: 25
//

#include <iostream>
#include "Point.h"

int main(int argc, const char * argv[]) {


    Point P1;
    Point *ptr = &P1;
    P1.setData(ptr, 3, 4);
    std::cout << "Radius of P1: " << P1.getRadius(ptr) << std::endl;
    P1.ScalePoint(ptr, 5);
    std::cout << "Radius of scaled P1: " << P1.getRadius(ptr) << std::endl;

    return 0;
};
