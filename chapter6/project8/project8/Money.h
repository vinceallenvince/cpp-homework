//
// Money.h
// Vince Allen
// Chapter 6, project8
//

#include <stdio.h>

class Money {
    int dollars;
    int cents;
public:
    void setData(int dollars, int cents) { this->dollars = dollars; this->cents = cents; };
    double getAmount();
};
