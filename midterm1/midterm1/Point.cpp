#include "Point.h"
#include <cmath>

void Point::setData(struct Point *p, int u, int v) {
    p->X = u;
    p->Y = v;
    p->R = p->calculateRadius(u, v);
};

float Point::calculateRadius(int x, int y) {
    return (float)sqrt(pow(x, 2) + pow(y, 2));
};

float Point::getRadius(struct Point *p) {
    return p->R;
};

int Point::getX(struct Point *) {
    return 1;
};

int Point::getY(struct Point *) {
    return 1;
};

void Point::ScalePoint(struct Point *p, int scale) {
    p->X = p->X * scale;
    p->Y = p->Y * scale;
    p->R = calculateRadius(p->X, p->Y);
};
