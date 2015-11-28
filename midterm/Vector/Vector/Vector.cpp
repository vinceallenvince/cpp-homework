#include "Vector.h"
#include <exception>

int const CAPACITY_FACTOR = 2;

// Constructors/Destructors

/**
 * Creates a new Vector.
 * @param size The vector's size.
 * @param val The value to initialize at each index.
 * @constructor
 */
Vector::Vector(int size, int val) {
    int capacity = this->calculateCapacity(size);
    this->size = size;
    this->capacity = capacity;
    this->ptr = new int[capacity];
    std::fill_n(this->ptr, size, val);
};

/**
 * Called when Vector falls out of scope or is explicitly deleted.
 * @deconstructor
 */
Vector::~Vector() {
    delete [] this->ptr;
    this->ptr = NULL;
}

/**
 * Called when Vector is passed by value or return from a function.
 * @copyconstructor
 */
Vector::Vector(const Vector &rhs) {

    this->ptr = new int[rhs.size];

    for (int i = 0; i < rhs.size; ++i) {
        *(this->ptr + i) = *(rhs.ptr + i);
    }

    size = rhs.size;
    capacity = rhs.capacity;
};

// Accessors

/**
 * @return The Vector's size.
 */
int Vector::getSize() {
    return this->size;
};

/**
 * @return The Vector's capacity.
 */
int Vector::getCapacity() {
    return this->capacity;
};


// Mutators

/**
 * @return Capacity based on passed size;
 * @private
 */
int Vector::calculateCapacity(int size) {
    return size * CAPACITY_FACTOR;
};

/**
 * Sets the Vector's size.
 * @param val The size to set.
 */
void Vector::setSize(int val) {
    this->size = val;
};

/**
 * Sets a value at the passed index.
 * @param index The index to set.
 * @param val The value to set.
 */
void Vector::setValue(int index, int val) {
    if (index > this->capacity || index < 0) {
        throw std::out_of_range("Vector::setValue index out of range.");
    }
    int *p = this->ptr + index;
    *p = val;
};


// Methods

/**
 * Returns the value at the passed index. If index is beyond the
 * Vector's size, throws an out_of_range error.
 */
int Vector::getValue(int index) {
    if (index >= this->size || index < 0) {
        throw std::out_of_range("Vector::getValue index out of range.");
    }
    int *ptr = this->ptr + index;
    return *ptr;
};

/**
 * Resizes the Vector to the passed size. If passed size is greater
 * than the Vector's capacity, allocates new memory and expands both
 * size and capacity. Also initializes any new indices to the
 * passed value.
 * @param size The size to set.
 * @param val The value to initialize any new indices.
 */
void Vector::resize(int size, int val) {

    int initialSize = this->getSize();
    int initialCapacity = this->getCapacity();

    // Shrink the vector
    if (initialSize >= size ) {
        this->setSize(size);
        return;
    }

    // Expand vector within capacity
    if (initialCapacity >= size) {
        this->setSize(size);
        for (int i = initialSize; i < initialCapacity; ++i) {
            this->setValue(i, val);
        }
        return;
    }

    // Allocate new memory for expanded vector

    //// save reference to current ptr
    int *current_ptr = this->ptr;

    //// calculate new capacity for new ptr
    int capacity = this->calculateCapacity(size);
    this->capacity = capacity;
    this->ptr = new int[capacity];

    //// copy old values to new ptr
    int currentSize = this->size;
    for (int i = 0; i < currentSize; ++i) {
        this->setValue(i, *current_ptr++);
    }

    //// initialize remaining values in new capacity
    for (int i = size; i < this->capacity; ++i) {
        this->setValue(i, val);
    }

    //// set new size
    this->setSize(size);

    //// nullify the pointer
    current_ptr = NULL;

};

/**
 * Pushes the passed value to the end of the Vector
 * and increments its size.
 * @param int The value to push.
 */
void Vector::push_back(int val) {
    int newSize = this->size + 1;
    this->resize(newSize);
    this->setValue(newSize - 1, val);

};

/**
 * Pushes the passed value to the front of the Vector
 * and increments its size.
 * @param int The value to push.
 */
void Vector::push_front(int val) {
    int newSize = this->size + 1;
    this->resize(newSize);
    for (int i = this->getSize() - 1; i >= 1; --i) {
        this->setValue(i, this->getValue(i - 1));
    }
    this->setValue(0, val);
};

/**
 * Removes the value at the end of the Vector
 * and decrements its size.
 */
void Vector::pop_back() {
    int newSize = this->size - 1;
    this->resize(newSize);
};

/**
 * Removes the value at the front of the Vector
 * and decrements its size.
 */
void Vector::pop_front() {
    for (int i = 1; i < this->getSize(); ++i) {
        this->setValue(i - 1, this->getValue(i));
    }

    int newSize = this->size - 1;
    this->resize(newSize);
};

/**
 * Iterates over the Vector and prints the
 * values within its size.
 */
void Vector::print() {
    for (int i = 0; i < this->getSize(); ++i) {
        std::cout << this->getValue(i) << std::endl;
    }
};

/**
 * Iterates over the Vector and prints the
 * values within its size.
 * @param len The length to print.
 */
void Vector::print(int len) {
    if (len <= 0) return;
    int l = len <= this->getSize() ? len : this->getSize();
    for (int i = 0; i < l; ++i) {
        std::cout << this->getValue(i) << std::endl;
    }
};

/**
 * Concatenates this Vector with the passed Vector.
 * @param Vector The Vector to concatenate.
 */
void Vector::concat(Vector vec) {

    // save reference to current ptr
    int *current_ptr = this->ptr;

    // calculate new size and capacity
    int newSize = this->size + vec.size;
    int capacity = this->calculateCapacity(newSize);
    this->capacity = capacity;
    this->ptr = new int[capacity];

    // copy old values to new ptr
    for (int i = 0; i < this->size; ++i) {
        this->setValue(i, *current_ptr++);
    }

    // copy values from passed ptr to new ptr
    int ptr_index = 0;
    for (int i = this->size; i < newSize; ++i) {
        this->setValue(i, vec.getValue(ptr_index));
        ++ptr_index;
    }

    // set new size
    this->setSize(newSize);

    // nullify temp pointer
    current_ptr = NULL;
};
