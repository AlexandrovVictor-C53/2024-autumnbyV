#include <cmath> 
#include <cstdio> 

int main(int argc, char* argv[])
{
    int n = 0;
    int x = 0;
    int a[1000] = { 0 };

    scanf_s("%d", &n);

    for (int i = 0; i < n; ++i)
    {
        scanf_s("%d", &a[i]);
    }

    scanf_s("%d", &x);


    int c_v = a[0];
    int md = abs(a[0] - x);

    for (int i = 1; i < n; ++i)
    {
        int c_swap = abs(a[i] - x);
        if (c_swap < md || (c_swap == md && a[i] < c_v))
        {
            c_v = a[i];
            md = c_swap;
        }
    }

    printf("%d\n", c_v);

    return 0;
}