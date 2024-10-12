#include<cstdio>

int main(int argc, char* argv[])
{
	int n = 0;
	int i = 0;
	int a[1000] = { 0 };
	scanf_s("%d", &n);

	for (i = 0; i < n; ++i)
	{
		scanf_s("%d", &a[i]);
	}
	for (i = n - 1; i >= 0; --i)
	{
		printf("%d ", a[i]);
	}
	return 0;
}