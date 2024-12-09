#include <cstdio>
#include <cmath>

main()
{
	int a[100], b[100], n, i, k, s[100], max;
	scanf_s("%d", &n);
	for (i = 0;i < n;i++)
	{
		scanf_s("%d", &a[i]);
	}
	for (i = 0;i < n;i++)
	{
		scanf_s("%d", &b[i]);
	}
	s[0] = a[0] * b[0];
	max = s[0];
	k = 1;
	for (i = 1;i < n;i++)
	{
		s[i] = a[i] * b[i];
		if (s[i] > max)
		{
			max = s[i];
			k = i + 1;
		}
	}
	printf("%d", k);
	return 0;
}