#include<cstdio>
#include <math.h>

int main(int argc, char* argv[])
{
    int i = 0;
    int j = 0;
    scanf_s("%d", &i);
    scanf_s("%d", &j);

    int swap_i = i;
    int swap_j = j;

    while (swap_j != 0)
    {
        int z = swap_j;
        swap_j = swap_i % swap_j;
        swap_i = z;
    }

    int a0 = 1;
    int a1 = 1;
    int a = 0;


    for (int k = 2; k < swap_i; ++k)
    {
        a = (a0 + a1) % 1000000000;
        a0 = a1;
        a1 = a;
    }

    printf("%d", a1);

    return 0;
}