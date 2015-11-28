//
//  HotDogStand.h
//  Chapter 7, Project4
//

#include <stdio.h>

class HotDogStand {

    char *id;
    int dailySales;

    static int totalSales;

public:

    HotDogStand();
    HotDogStand(char *id, int dailySales = 0);

    char* getID() { return this->id; };
    int getDailySales() { return this->dailySales; };
    void justSold();

    static int getTotalSales() {
        return totalSales;
    };

    static void incrementTotalSales() {
        totalSales++;
    };

};
