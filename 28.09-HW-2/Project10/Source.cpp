#include <iostream>
#include <math.h>

int k =  0;
int w =  0;
int a1 = 0;
int b1 = 0;
int a2 = 0;
int b2 = 0;
int a3 = 0;
int b3 = 0;

int main(int argc, char* argv[])
{
    scanf_s("%d",  &k);
    scanf_s("%d",  &w);

    scanf_s("%d", &a1);
    scanf_s("%d", &b1);
    scanf_s("%d", &a2);
    scanf_s("%d", &b2);
    scanf_s("%d", &a3);
    scanf_s("%d", &b3);

    if (b1 + b2 + b3 >= k)
    {
        if (b1 + b2 >= k && a1 + a2 <= w)
        {
            printf( "YES" );
            return 0;
        }
        else if (b1 + b3 >= k && a1 + a3 <= w)
        {
            printf( "YES" );
            return 0;
        }
        else if (b2 + b3 >= k && a2 + a3 <= w)
        {
            printf( "YES" );
            return 0;
        }
        else if (b1 + b2 + b3 >= k && a1 + a2 + a3 <= w)
        {
            printf( "YES" );
            return 0;
        }
        else if (b1 >= k && a1 <= w)
        {
            printf( "YES" );
            return 0;
        }
        else if (b2 >= k && a2 <= w)
        {
            printf( "YES" );
            return 0;
        }
        else if (b3 >= k && a3 <= w)
        {
            printf( "YES" );
            return 0;
        }
    }
    printf( "NO" );
    return 0;
}