//
// Test.h
// Vince Allen
// Chapter 6, project8
//

typedef bool (*fn)();

struct Test {
    char description[128];
    fn func;
};
