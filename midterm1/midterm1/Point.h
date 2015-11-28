#include <stdio.h>

struct Point {
    int X, Y;   // position
    float R;    // radius – distance from origin

    void setData(struct Point *p, int u, int v);
    float getRadius(struct Point *);
    int getX(struct Point *);
    int getY(struct Point *);
    void ScalePoint(struct Point *, int scale);
    float calculateRadius(int x, int y);
};
