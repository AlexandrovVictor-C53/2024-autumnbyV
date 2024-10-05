#include<iostream>

int main(int argc, char* argv[])
{
    int h = 0;
    int a = 0;
    int b = 0;

    scanf_s("%d", &h);
    scanf_s("%d", &a);
    scanf_s("%d", &b);

    int d = (h - b - 1) / (a - b) + 1 + 2 * h;
    int e = 1 + 2 * h;

    int r = (d * (d / e) + e * (e / d)) / (d / e + e / d) - 2 * h;
    printf("%d", r);

    return EXIT_SUCCESS;
}