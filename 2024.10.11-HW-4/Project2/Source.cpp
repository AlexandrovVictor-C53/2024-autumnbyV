#include<cstdio>

int main(int argc, char* argv[])
{
	int n = 0;
	int i = 0;
	int a[1001] = { 0 };
	int k = 0;
	int l = 0;
	int r = 0;
	scanf_s("%d", &n);

	for (i = 1; i <= n; ++i)
	{
		scanf_s("%d", &a[i]);
	}
	{
		scanf_s("%d", &l);
	}
	{
		scanf_s("%d", &r);
	}
	k = l;
	for (i = l + 1; i <= r; ++i)
	{
		if (a[i] > a[k])
		{
			k = i;
		}
	}
	printf("%d %d", a[k], k);
	return 0;
}