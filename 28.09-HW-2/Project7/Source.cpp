#include <iostream> 
#include <math.h> 

int main()
{
    int k, m, n;
    scanf_s("%d %d %d", &k, &m, &n);

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