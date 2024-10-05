#include<cstdio>
#include <math.h>
int main(int argc, char* argv[])
{
    int a = 0;
    int b = 0;
    scanf_s("%d", &a);
    scanf_s("%d", &b);

    int swap_a = a;
    int swap_b = b;

    while (swap_b)
    {
        int z = swap_b;
        swap_b = swap_a % swap_b;
        swap_a = z;
    }



    int f = (a * b) / swap_a;
    printf("%d", f);

    return 0;
}