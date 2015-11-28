//
// Test.h
// Vince Allen
// Chapter 6, project10
//

typedef bool (*fn)();

struct Test {
    char description[128];
    fn func;
};
