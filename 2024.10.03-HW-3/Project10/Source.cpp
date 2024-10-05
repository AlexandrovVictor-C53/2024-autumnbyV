#include<cstdio>
#include <math.h>

int main(int argc, char* argv[])
{
	int a = 0;
	int b = 0;
	int q = 0;
	int d = 0;

	scanf_s("%d", &a);

	for (int i = 0; i < a; ++i)
	{
		scanf_s("%d", &b);
		if (b > 0)
		{
			++q;
		}
		else
		{
			q = 0;
		}
		if (q > d)
		{
			d = q;
		}
	}

	printf("%d", d);
	return 0;
}