#include <cstdio>
#include <cmath>

int main(int argc, char* argv[])
{
	int n = 0;
	int b = 0;
	int c = 0;
	int i = 0;

	scanf_s("%d", &n);

	for (i = 1; i <= n; ++i)
	{
		scanf_s("%d", &b);
		c += b;
	}

	if (c <= n / 2)
	{
		printf("%d", c);
	}

	else
	{
		printf("%d", n - c);
	}
	return 0;
}
