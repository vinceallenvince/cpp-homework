/**
 * Quiz 2 - Vince Allen
 *
 * - Create a class X that contains four member functions, with 0, 1, 2, and 3 int arguments, respectively.
 * - Create a main( ) that makes an object of your class and calls each of the member functions.
 * - Now modify the class so it has instead a single member function with all the arguments defaulted.
 *   Does this change your main( )?
 *
 * OUTPUT:
 * 
 * member functions: 10
 * default values: 10
 */

#include <iostream>
using namespace std;

class MyClass {

public:
    int funcA();
    int funcB(int B1);
    int funcC(int C1, int C2);
    int funcD(int D1, int D2, int D3);
    int myFunc(int B1 = 1, int C1 = 1, int C2 = 2, int D1 = 1, int D2 = 2, int D3 = 3);
};

int main(int argc, const char * argv[]) {

    MyClass aClass;
    int a = aClass.funcA();
    int b = aClass.funcB(1);
    int c = aClass.funcC(1, 2);
    int d = aClass.funcD(1, 2, 3);

    cout << "member functions: " << a + b + c + d << endl;

    int myVal = aClass.myFunc();

    cout << "default values: " << myVal << endl;

    return 0;
}

int MyClass::funcA() {
    return 0;
};

int MyClass::funcB(int B1) {
    return B1;
};

int MyClass::funcC(int C1, int C2) {
    return C1 + C2;
};

int MyClass::funcD(int D1, int D2, int D3) {
    return D1 + D2 + D3;
};

int MyClass::myFunc(int B1, int C1, int C2, int D1, int D2, int D3) {
    return B1 + C1 + C2 + D1 + D2 + D3;
};
