#include <iostream>
#include <math.h>
#include <algorithm>

int main(int argc, char* argv[])
{
    int x1, y1, z1, x2, y2, z2;
    int xx1, yy1, zz1, xx2, yy2, zz2;
    scanf_s("%d", &x1);
    scanf_s("%d", &y1);
    scanf_s("%d", &z1);
    scanf_s("%d", &x2);
    scanf_s("%d", &y2);
    scanf_s("%d", &z2);
   
    yy1 = x1 + y1 + z1 - max(x1, max(y1, z1)) - min(x1, min(y1, z1));
    xx1 = max(x1, max(y1, z1));
    zz1 = min(x1, min(y1, z1));
    yy2 = x2 + y2 + z2 - max(x2, max(y2, z2)) - min(x2, min(y2, z2));
    xx2 = max(x2, max(y2, z2));
    zz2 = min(x2, min(y2, z2));
    if (xx1 == xx2 && yy1 == yy2 && zz1 == zz2) {
        printf( "Boxes are equal");
    }
    else if (xx1 >= xx2 && yy1 >= yy2 && zz1 >= zz2) {
        printf( "The first box is larger than the second one");
    }
    else if (xx1 <= xx2 && yy1 <= yy2 && zz1 <= zz2) {
        printf( "The first box is smaller than the second one");
    }
    else {
        printf("Boxes are incomparable");
    }
    return 0;
}