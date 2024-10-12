#include <cstdio>

int main(int argc, char* argv[])
{
    int n = 0;
    scanf_s("%d", &n);

    int rostRebyat[100] = { 0 };

    for (int i = 0; i < n; ++i)
    {
        scanf_s("%d", &rostRebyat[i]);
    }

    int pRost = 0;
    scanf_s("%d", &pRost);

    int pos = 0;

    while (pos < n && rostRebyat[pos] >= pRost)
    {
        ++pos;
    }

    printf("%d", pos + 1);

    return 0;
}