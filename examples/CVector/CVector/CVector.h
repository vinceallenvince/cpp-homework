#ifndef __classExample01__CVector__
#define __classExample01__CVector__

#include <stdio.h>
#include <iostream>

class CVector {
    double x = 0;
    double y = 0;
public:
    CVector() {
        this->x = 0;
        this->y = 0;
    };
    CVector(double x, double y) {
        this->x = x;
        this->y = y;
    };

    ~CVector();
    // TODO: copy constructor


    // TODO: use const where helpful

    // TODO: operator overloading for +, -, *, /

    const double getX();
    const double getY();
    void setX(const int x);
    void setY(const int y);

    void add(const CVector &v);
    void sub(const CVector &v);
    void mult(const double n);
    void div(const double n);
    double mag();
    void limit(const double high);
    void limit(const double high, const double low);
    void normalize();
    double distance(CVector &v);
    void rotate(const double radians);
    double dot(CVector &v);

    static CVector VectorAdd(CVector &v1, CVector &v2);
    static CVector VectorSub(CVector &v1, CVector &v2);
    static CVector VectorMult(CVector &v1, CVector &v2);
    static CVector VectorDiv(CVector &v1, CVector &v2);
    static double VectorDistance(CVector &v1, CVector &v2);
    static CVector VectorMidpoint(CVector &v1, CVector &v2);
    static double VectorAngleBetween(CVector &v1, CVector &v2);

};

#endif /* defined(__classExample01__CVector__) */
