#include "CVector.h"
#include <cmath>

CVector::~CVector() {
    std::cout << "Destructor!" << std::endl;
};

// accessors
const double CVector::getX() {
    return this->x;
};

const double CVector::getY() {
    return this->y;
};

// mutators
void CVector::setX(const int x) {
    this->x = x;
};

void CVector::setY(const int y) {
    this->y = y;
};

// methods
void CVector::add(const CVector &v) {
    x += v.x;
    y += v.y;
}

void CVector::sub(const CVector &v) {
    x -= v.x;
    y -= v.y;
}

void CVector::mult(const double n) {
    x *= n;
    y *= n;
}

void CVector::div(const double n) {
    x /= n;
    y /= n;
}

double CVector::mag() {
    return sqrt((x * x) + (y * y));
}

void CVector::limit(const double high) {
    if (this->mag() > high) {
        this->normalize();
        this->mult(high);
    }
}

void CVector::limit(const double high, const double low) {
    if (this->mag() > high) {
        this->normalize();
        this->mult(high);
    }
    if (this->mag() < low) {
        this->normalize();
        this->mult(low);
    }
}

void CVector::normalize() {
    double m = this->mag();
    if (m != 0) {
        this->div(m);
    }
};

double CVector::distance(CVector &v) {
    return sqrt(powl(v.x - this->x, 2) + powl(v.y - this->y, 2));
};

void CVector::rotate(const double radians) {
    double c = cos(radians);
    double s = sin(radians);
    this->x = this->x * c - this->y * s;
    this->y = this->x * s + this->y * c;
};

double CVector::dot(CVector &v) {
    return this->x * v.x + this->y * v.y;
};

CVector CVector::VectorAdd(CVector &v1, CVector &v2) {
    CVector v(v1.getX() + v2.getX(), v1.getY() + v2.getY());
    return v;
}

CVector CVector::VectorSub(CVector &v1, CVector &v2) {
    CVector v(v1.getX() - v2.getX(), v1.getY() - v2.getY());
    return v;
}

CVector CVector::VectorMult(CVector &v1, CVector &v2) {
    CVector v(v1.getX() * v2.getX(), v1.getY() * v2.getY());
    return v;
}

CVector CVector::VectorDiv(CVector &v1, CVector &v2) {
    CVector v(v1.getX() / v2.getX(), v1.getY() / v2.getY());
    return v;
}

double CVector::VectorDistance(CVector &v1, CVector &v2) {
    return sqrt(pow(v2.x - v1.x, 2) + pow(v2.y - v1.y, 2));
}

CVector CVector::VectorMidpoint(CVector &v1, CVector &v2) {
    CVector v = CVector::VectorAdd(v1, v2);
    v.div(2);
    return v;
}

double CVector::VectorAngleBetween(CVector &v1, CVector &v2) {
    double dot = v1.dot(v2);
    return acos(dot / (v1.mag() * v2.mag()));
}
