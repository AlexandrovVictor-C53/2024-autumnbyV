#include <stdio.h> 
#include <math.h> 
#include <cmath> 


int main()
{
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    int x1 = 0;
    int x2 = 0;


    scanf_s("%d", &a);
    scanf_s("%d", &b);
    scanf_s("%d", &c);

    d = b * b - 4 * a * c;
    if (d > 0) 
    {
        x1 = ((-b) + sqrt(d)) / (2 * a);
        x2 = ((-b) - sqrt(d)) / (2 * a);
        printf("%d \n", &x1);
        printf("%d", &x2);
    }
    if (d == 0) 
    {
        x1 = -(b / (2 * a));
        printf("%d \n", &x1);
    }
    if (d < 0) 
       printf("D < 0, ƒействительных корней уравнени€ не существует");
}