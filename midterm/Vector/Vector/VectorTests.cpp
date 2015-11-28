#include "VectorTests.h"

const int TOTAL_TESTS = 13;

int vectorTests() {

    Test vectorTests[TOTAL_TESTS];

    strcpy(vectorTests[0].description, "Should create a zero length vector.");
    strcpy(vectorTests[1].description, "Should create a vector of a specific length.");
    strcpy(vectorTests[2].description, "Should create a vector of a specific length with a specific value.");
    strcpy(vectorTests[3].description, "Should create a vector with a capacity > the size.");
    strcpy(vectorTests[4].description, "Should set a value at a specified index.");
    strcpy(vectorTests[5].description, "Should shrink the vector.");
    strcpy(vectorTests[6].description, "Should resize the vector wout allocating new memory if size is <= capacity.");
    strcpy(vectorTests[7].description, "Should resize the vector by allocating new memory if size is > capacity.");
    strcpy(vectorTests[8].description, "Should push a value to the back of the vector.");
    strcpy(vectorTests[9].description, "Should push a value to the front of the vector.");
    strcpy(vectorTests[10].description, "Should pop a value off the back of the vector.");
    strcpy(vectorTests[11].description, "Should pop a value off the front of the vector.");
    strcpy(vectorTests[12].description, "Should concatenate vectors.");

    vectorTests[0].func = vectorTest0;
    vectorTests[1].func = vectorTest1;
    vectorTests[2].func = vectorTest2;
    vectorTests[3].func = vectorTest3;
    vectorTests[4].func = vectorTest4;
    vectorTests[5].func = vectorTest5;
    vectorTests[6].func = vectorTest6;
    vectorTests[7].func = vectorTest7;
    vectorTests[8].func = vectorTest8;
    vectorTests[9].func = vectorTest9;
    vectorTests[10].func = vectorTest10;
    vectorTests[11].func = vectorTest11;
    vectorTests[12].func = vectorTest12;

    //

    TestRunner::runTests(vectorTests, TOTAL_TESTS);

    std::cout << std::endl << "All tests succeeded." << std::endl << std::endl;

    return 1;
};

// Should create a zero length vector.
bool vectorTest0() {
    Vector v;
    return v.getSize() == 0;
};

// Should create a vector of a specific length.
bool vectorTest1() {
    Vector v(11);
    return v.getSize() == 11;
};

// Should create a vector of a specific length with a specific value.
bool vectorTest2() {
    int size = 3;
    Vector v(size, 5);
    return v.getSize() == size && v.getValue(2) == 5;
};

// Should create a vector with a capacity > the size.
bool vectorTest3() {
    int size = 3;
    Vector v(size, 0);
    return v.getCapacity() > size;
};

// Should set a value at a specified index.
bool vectorTest4() {
    int size = 3;
    Vector v(size, 0);
    v.setValue(2, 5);
    return v.getValue(2) == 5;
};

// Should shrink the vector.
bool vectorTest5() {
    int size = 10;
    int resize = 5;
    Vector v(size, 300);
    v.resize(resize);

    bool thrown = false;
    try {
        v.getValue(resize + 1);
    } catch (const std::out_of_range& e) {
        thrown = true;
    }
    
    return v.getValue(resize - 1) == 300 && thrown;
}

// Should resize the vector wout allocating new memory if size is <= capacity.
bool vectorTest6() {
    int size = 10;
    int resize = 15;
    Vector vA(size, 300);
    vA.resize(resize, 80);

    bool thrown = false;
    try {
        vA.getValue(resize + 1);
    } catch (const std::out_of_range& e) {
        thrown = true;
    }

    return vA.getValue(size - 1) == 300 && vA.getValue(size + 1) == 80 && thrown;
}

// Should resize the vector by allocating new memory if size is > capacity.
bool vectorTest7() {
    int size = 10;
    int resize = 30;
    Vector v(size, 300);
    v.resize(resize);

    bool thrown = false;
    try {
        v.getValue(resize + 1);
    } catch (const std::out_of_range& e) {
        thrown = true;
    }

    return v.getValue(size - 1) == 300 && v.getValue(size + 1) == 0 && v.getValue(resize - 1) == 0 && thrown;
}

// Should push a value to the back of the vector.
bool vectorTest8() {
    int size = 10;
    Vector v(size, 300);
    v.push_back(1);

    return v.getValue(v.getSize() - 1) == 1;
}

// Should push a value to the front of the vector.
bool vectorTest9() {
    int size = 10;
    Vector v(size, 300);
    v.push_front(1);

    return v.getValue(0) == 1 && v.getValue(1) == 300 && v.getValue(v.getSize() - 1) == 300;
}

// Should pop a value off the back of the vector.
bool vectorTest10() {
    int size = 10;
    Vector v(size, 300);
    v.pop_back();

    bool thrown = false;
    try {
        v.getValue(size - 1);
    } catch (const std::out_of_range& e) {
        thrown = true;
    }

    return v.getValue(8) == 300 && thrown;
}

// Should pop a value off the front of the vector.
bool vectorTest11() {
    int size = 10;
    Vector v(size);

    for (int i = 0; i < v.getSize(); ++i) {
        v.setValue(i, i);
    }

    v.pop_front();

    int val = v.getValue(1);
    std::cout << val << std::endl;
    bool thrown = false;
    try {
        v.getValue(size - 1);
    } catch (const std::out_of_range& e) {
        thrown = true;
    }

    return v.getValue(0) == 1 && thrown;
}

bool vectorTest12() {
    int size = 10;
    Vector vA(size, 10);
    Vector vB(size * 2, 30);

    vA.concat(vB);

    bool thrown = false;
    try {
        vA.getValue(vA.getSize() + vB.getSize() + 1);
    } catch (const std::out_of_range& e) {
        thrown = true;
    }

    return vA.getValue(size - 1) == 10 && vA.getValue(size + 1) == 30 && vA.getValue((size * 2) - 1) == 30 && thrown;
};
