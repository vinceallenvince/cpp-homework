#ifndef __Vector__Vector__
#define __Vector__Vector__

#include <stdio.h>
#include <iostream>

class Vector {
    
    int size;
    int capacity;
    int *ptr;
    int calculateCapacity(int size);

public:

    Vector(int size = 0, int val = 0);
    ~Vector();
    Vector(const Vector &rhs); // TODO: copy constructor

    // accessors
    int getSize();
    int getCapacity();

    // mutators
    void setSize(int val);
    void setValue(int index, int val);
    
    // methods
    int getValue(int index);
    void resize(int size, int val = 0);
    void push_back(int val);
    void push_front(int val);
    void pop_back();
    void pop_front();
    void print();
    void print(int len);
    void concat(Vector vec); //concatenate rhs vector to existing vector
};

#endif /* defined(__Vector__Vector__) */
