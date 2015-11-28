/**
 * Vince Allen
 *
 * Chapter 3, Project 4
 * Compute the gravitaional force in dynes between two bodies given
 * their mass and the distance bw them.
 *
 * 1 dyne = g * sec ^ 2
 *
 * F = (G x m1 x m2) / d ^ 2
 *
 * G = 6.673 x 10 ^ -8 cm ^ 3 / (g * sec ^ 2)
 */

#include <iostream>
#include <cmath>

double gravitationalForce(double massObj1, double massObj2, double distance);
double const G = 6.673 * pow(10, -8);

int main(int argc, const char * argv[]) {

    char again = 'Y';
    double massObj1, massObj2, distance;

    while (again != 'n' && again != 'N') {
        std::cout << "Enter the mass of object 1." << std::endl;
        std::cin >> massObj1;

        std::cout << "Enter the mass of object 2." << std::endl;
        std::cin >> massObj2;

        std::cout << "Enter the distance between the objects." << std::endl;
        std::cin >> distance;

        std::cout << "The gravitational force between the objects is " << gravitationalForce(massObj1, massObj2, distance) << " dynes." << std::endl;

        std::cout << "Again (Y or n) ";
        std::cin >> again;
    }
    return 0;
}

double gravitationalForce(double massObj1, double massObj2, double distance) {
    return (G * massObj1 * massObj2) / pow(distance, 2);
}
