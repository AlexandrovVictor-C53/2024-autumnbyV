#include <cstdio>
#include <cmath>

int main(int argc, char* argv[])
{
	int a = 0;
	int b = 0;
	int n = 0;
	int c = 0;
	int d = 0;

	scanf_s("%d", &n);
	scanf_s("%d", &a);
	scanf_s("%d", &b);
	scanf_s("%d", &c);
	scanf_s("%d", &d);

	int m[1000] = { 0 };

	for (int i = 0; i < n; ++i)
	{
		m[i] = i + 1;
	}

	for (int i = a - 1, j = b - 1; i < j; ++i, --j)
	{
		int f = m[i];
		m[i] = m[j];
		m[j] = f;
	}

	for (int i = c - 1, j = d - 1; i < j; ++i, --j)
	{
		int f = m[i];
		m[i] = m[j];
		m[j] = f;
	}

	for (int i = 0; i < n; ++i)
	{
		printf(" %d", m[i]);
	}

	return 0;
}