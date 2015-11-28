#include <iostream>
#include <iomanip>
#include <cmath>
#include <ctime>

using namespace std;

double mapRange(double val, double min1, double max1, double min2, double max2);

int main(int argc, const char * argv[]) {

    clock_t start;


    int i = 0;
    while (i < 1000) {

        double duration = 0;
        start = clock();

        while (duration < CLOCKS_PER_SEC * 0.0016) {
            duration += (clock() - start) / (double) CLOCKS_PER_SEC;
        }

        double val = roundl(mapRange(sin(i * 0.15), -1, 1, 1, 50));
        cout << right << setw(val) << setfill(' ') << "*" << endl;
        i++;
    }
    return 0;
}

double mapRange(double val, double min1, double max1, double min2, double max2) {
    double unitratio = (val - min1) / (max1 - min1);
    return (unitratio * (max2 - min2)) + min2;
}
