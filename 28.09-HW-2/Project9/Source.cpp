#include <iostream>
#include <cmath>
#include <math.h> 

int main(int argc, char* argv[])
{
    int k = 0;
    int m = 0;
    int n = 0;

    scanf_s("%d", &k);
    scanf_s("%d", &m);
    scanf_s("%d", &n);

    if (n <= k) {
        printf("%d", 2 * m);
    }
    else {
        if (((n * 2) % k) == 0) {
            printf("%d", m * (n * 2 / k));
        }
        else {
            printf("%d", m * (1 + (n * 2 / k)));
        }
    }
}