//
//  HotDogStand.cpp
//  Chapter 7, Project4
//

#include "HotDogStand.h"

HotDogStand::HotDogStand() {
    char id[7] = "000000";
    this->id = &id[0];
    this->dailySales = 0;
};

HotDogStand::HotDogStand(char *id, int dailySales) {
    this->id = id;
    this->dailySales = dailySales;
};

void HotDogStand::justSold() {
    this->dailySales++;
    this->incrementTotalSales();
};
