#ifndef __classExample01__CVector__
#define __classExample01__CVector__

#include <stdio.h>

class CVector {
    double x = 0;
    double y = 0;
public:
    void init(double x, double y) {
        this->x = x;
        this->y = y;
    };
    double getX() { return x; };
    double getY() { return y; };
    void add(CVector v);
    void sub(CVector v);
    void mult(double n);
    void div(double n);
    double mag();
    void limit(double high);
    void limit(double high, double low);
    void normalize();
    double distance(CVector v);
    void rotate(double radians);
    double dot(CVector v);

    static CVector VectorAdd(CVector v1, CVector v2);
    static CVector VectorSub(CVector v1, CVector v2);
    static CVector VectorMult(CVector v1, CVector v2);
    static CVector VectorDiv(CVector v1, CVector v2);
    static double VectorDistance(CVector v1, CVector v2);
    static CVector VectorMidpoint(CVector v1, CVector v2);
    static double VectorAngleBetween(CVector v1, CVector v2);

};

#endif /* defined(__classExample01__CVector__) */
