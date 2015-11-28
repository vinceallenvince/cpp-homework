#include "Point.h"
#include <cmath>

void Point::setData(int u, int v) {
    this->X = u;
    this->Y = v;
    this->R = this->calculateRadius(u, v);
};

float Point::calculateRadius(int x, int y) {
    return (float)sqrt(pow(x, 2) + pow(y, 2));
};

float Point::getRadius() const {
    return this->R;
};

int Point::getX() const {
    return this->X;
};

int Point::getY() const {
    return this->Y;
};

void Point::ScalePoint(int scale) {
    this->X = this->X * scale;
    this->Y = this->Y * scale;
    this->R = calculateRadius(this->X, this->Y);
};
