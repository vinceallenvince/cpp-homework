#include <stdio.h>

struct Point {
    int X, Y;   // position
    float R;    // radius – distance from origin

    void setData(int u, int v);
    float getRadius() const;
    int getX() const;
    int getY() const;
    void ScalePoint(int scale);
    float calculateRadius(int x, int y);
};
