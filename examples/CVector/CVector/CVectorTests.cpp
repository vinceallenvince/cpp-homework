#include "CVectorTests.h"

const int TOTAL_TESTS = 18;

void cvectorTests() {

    Test cvectorTests[TOTAL_TESTS];

     strcpy(cvectorTests[0].description, "Should add two vectors.");
     strcpy(cvectorTests[1].description, "Should subtract two vectors.");
     strcpy(cvectorTests[2].description, "Should multiply a vector by a scalar value.");
     strcpy(cvectorTests[3].description, "Should divide a vector by a scalar value.");
     strcpy(cvectorTests[4].description, "Should return the magnitude of a vector.");
     strcpy(cvectorTests[5].description, "Should limit the magnitude of a vector.");
     strcpy(cvectorTests[6].description, "Should normalize (ie. divide a vector by its magnitude to reduce its magnitude to 1).");
     strcpy(cvectorTests[7].description, "Should calculate the distance between this vector and a passed vector.");
     strcpy(cvectorTests[8].description, "Should rotate a vector using a passed angle in radians.");
     strcpy(cvectorTests[9].description, "Should should add two vectors.");
     strcpy(cvectorTests[10].description, "Should subtract two vectors.");
     strcpy(cvectorTests[11].description, "Should multiply two vectors.");
     strcpy(cvectorTests[12].description, "Should divide two vectors.");
     strcpy(cvectorTests[13].description, "Should return the distance between two vectors.");
     strcpy(cvectorTests[14].description, "Should return the midpoint between two vectors.");
     strcpy(cvectorTests[15].description, "Should add two vectors via pointer.");
     strcpy(cvectorTests[16].description, "Should subtract two vectors via reference.");
     strcpy(cvectorTests[17].description, "Destructor");
    
     cvectorTests[0].func = cvectorTest0;
     cvectorTests[1].func = cvectorTest1;
     cvectorTests[2].func = cvectorTest2;
     cvectorTests[3].func = cvectorTest3;
     cvectorTests[4].func = cvectorTest4;
     cvectorTests[5].func = cvectorTest5;
     cvectorTests[6].func = cvectorTest6;
     cvectorTests[7].func = cvectorTest7;
     cvectorTests[8].func = cvectorTest8;
     cvectorTests[9].func = cvectorTest9;
     cvectorTests[10].func = cvectorTest10;
     cvectorTests[11].func = cvectorTest11;
     cvectorTests[12].func = cvectorTest12;
     cvectorTests[13].func = cvectorTest13;
     cvectorTests[14].func = cvectorTest14;
     cvectorTests[15].func = cvectorTest15;
     cvectorTests[16].func = cvectorTest16;
     cvectorTests[17].func = cvectorTest17;

     TestRunner::runTests(cvectorTests, TOTAL_TESTS);

     std::cout << std::endl << "All tests succeeded." << std::endl << std::endl;

};

void cvectorTestBefore(CVector &a, CVector &b, double aValX, double aValY, double bValX, double bValY) {
    a.setX(aValX);
    a.setY(aValY);
    b.setX(bValX);
    b.setY(bValY);
}

bool cvectorTest0() {
    CVector a;
    CVector b;
    cvectorTestBefore(a, b, 10, 20, 110, 160);

    a.add(b);
    return a.getX() == 120 && a.getY() == 180;
};

bool cvectorTest1() {
    CVector a;
    CVector b;
    cvectorTestBefore(a, b, 10, 20, 110, 160);

    a.sub(b);
    return a.getX() == -100 && a.getY() == -140;
};

bool cvectorTest2() {
    CVector a;
    CVector b;
    cvectorTestBefore(a, b, 10, 20, 110, 160);

    a.mult(10);
    return a.getX() == 100 && a.getY() == 200;
};

bool cvectorTest3() {
    CVector a;
    CVector b;
    cvectorTestBefore(a, b, 10, 20, 110, 160);

    a.div(100);
    return a.getX() == 0.1 && a.getY() == 0.2;
};

bool cvectorTest4() {
    CVector a;
    CVector b;
    cvectorTestBefore(a, b, 10, 20, 110, 160);

    return roundl(a.mag()) == 22;
};

bool cvectorTest5() {
    CVector a;
    CVector b;
    cvectorTestBefore(a, b, 10, 20, 110, 160);
    a.limit(15);

    CVector c;
    CVector d;
    cvectorTestBefore(c, d, 10, 20, 50, 60);
    d.limit(200, 180);

    return round(a.mag()) == 15 && roundl(d.mag()) == 180;
};

bool cvectorTest6() {
    CVector a;
    CVector b;
    cvectorTestBefore(a, b, 10, 20, 110, 160);
    a.normalize();
    return roundl(a.mag()) == 1;
};

bool cvectorTest7() {
    CVector a;
    CVector b;
    cvectorTestBefore(a, b, 10, 20, 110, 160);
    double d = a.distance(b);
    return roundl(d) == 172;
};

bool cvectorTest8() {
    CVector a;
    CVector b;
    cvectorTestBefore(a, b, 10, 10, 0, 0);
    const double PI = 2 * acos(0.0);
    a.rotate(PI);
    return roundl(a.getX()) == -10 && roundl(a.getY()) == -10;
};

bool cvectorTest9() {
    CVector a;
    CVector b;
    cvectorTestBefore(a, b, 10, 20, 110, 160);
    CVector vAdd = CVector::VectorAdd(a, b);
    return vAdd.getX() == 120;
};

bool cvectorTest10() {
    CVector a;
    CVector b;
    cvectorTestBefore(a, b, 10, 20, 110, 160);
    CVector vSub = CVector::VectorSub(a, b);
    return vSub.getX() == -100;
};

bool cvectorTest11() {
    CVector a;
    CVector b;
    cvectorTestBefore(a, b, 10, 20, 110, 160);
    CVector vMult = CVector::VectorMult(a, b);
    return vMult.getX() == 1100;
};

bool cvectorTest12() {
    CVector a;
    CVector b;
    cvectorTestBefore(a, b, 110, 160, 10, 20);
    CVector vDiv = CVector::VectorDiv(a, b);
    return roundl(vDiv.getX()) == 11;
};

bool cvectorTest13() {
    CVector a;
    CVector b;
    cvectorTestBefore(a, b, 110, 160, 10, 20);
    double db = CVector::VectorDistance(a, b);
    return roundl(db) == 172;
};

bool cvectorTest14() {
    CVector a;
    CVector b;
    cvectorTestBefore(a, b, 110, 160, 10, 20);
    CVector vMidPt = CVector::VectorMidpoint(a, b);
    return roundl(vMidPt.getX()) == 60 && roundl(vMidPt.getY()) == 90;
};

bool cvectorTest15() {
    return true;
};

bool cvectorTest16() {
    return true;
}


bool cvectorTest17() {
    return true;
}
