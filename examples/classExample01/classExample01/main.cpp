#include <iostream>
#include <cmath>
using namespace std;
#include "CVector.h"

//#define NDEBUG
#include <assert.h>

CVector a;
CVector b;

void before(CVector &a, CVector &b, double aValX, double aValY, double bValX, double bValY);

int main(int argc, const char * argv[]) {

    // should add two vectors
    before(a, b, 10, 20, 110, 160);

    a.add(b);
    assert(a.getX() == 120);
    assert(a.getY() == 180);

    // should subtract two vectors
    before(a, b, 10, 20, 110, 160);

    a.sub(b);
    assert(a.getX() == -100);
    assert(a.getY() == -140);

    // should multiply a vector by a scalar value
    before(a, b, 10, 20, 110, 160);

    a.mult(10);
    assert(a.getX() == 100);
    assert(a.getY() == 200);

    // should divide a vector by a scalar value
    before(a, b, 10, 20, 110, 160);

    a.div(100);
    assert(a.getX() == 0.1);
    assert(a.getY() == 0.2);

    // should return the magnitude of a vector
    before(a, b, 10, 20, 110, 160);
    assert(roundl(a.mag()) == 22);

    // should limit the magnitude of a vector
    before(a, b, 10, 20, 110, 160);
    a.limit(20);
    assert(a.mag() == 20);

    before(a, b, 10, 20, 110, 160);
    a.limit(200, 100);
    assert(roundl(a.mag()) == 100);

    // should normalize (ie. divide a vector by its magnitude to reduce its magnitude to 1)
    before(a, b, 10, 20, 110, 160);
    a.normalize();
    assert(roundl(a.mag()) == 1);

    // should calculate the distance between this vector and a passed vector
    before(a, b, 10, 20, 110, 160);
    double d = a.distance(b);
    assert(roundl(d) == 172);

    // should rotate a vector using a passed angle in radians
    before(a, b, 10, 10, 0, 0);
    const double PI = 2*acos(0.0);
    a.rotate(PI);
    assert(roundl(a.getX()) == -10);
    assert(roundl(a.getY()) == -10);

    // should return the midpoint between this vector and a passed vector
    before(a, b, 10, 20, 110, 160);

    // should add two vectors
    before(a, b, 10, 20, 110, 160);
    CVector vAdd = CVector::VectorAdd(a, b);
    assert(vAdd.getX() == 120);

    // should subtract two vectors
    before(a, b, 10, 20, 110, 160);
    CVector vSub = CVector::VectorSub(a, b);
    assert(vSub.getX() == -100);

    // should multiply two vectors
    before(a, b, 10, 20, 110, 160);
    CVector vMult = CVector::VectorMult(a, b);
    assert(vMult.getX() == 1100);

    // should divide two vectors
    before(a, b, 110, 160, 10, 20);
    CVector vDiv = CVector::VectorDiv(a, b);
    assert(roundl(vDiv.getX()) == 11);

    // should return the distance between two vectors.
    before(a, b, 110, 160, 10, 20);
    double db = CVector::VectorDistance(a, b);
    assert(roundl(db) == 172);

    // should return the midpoint between two vectors.
    before(a, b, 110, 160, 10, 20);
    CVector vMidPt = CVector::VectorMidpoint(a, b);
    assert(roundl(vMidPt.getX()) == 60);
    assert(roundl(vMidPt.getY()) == 90);

    return 0;
}

void before(CVector &a, CVector &b, double aValX, double aValY, double bValX, double bValY) {
    a.init(aValX, aValY);
    b.init(bValX, bValY);
}
