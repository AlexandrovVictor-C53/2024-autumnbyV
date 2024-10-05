#include<cstdio>
#include <math.h>

int main(int argc, char* argv[])
{
	int m = 0;
	int n = 0;
	scanf_s("%d", &n);
	scanf_s("%d", &m);
	int swap_n = n;
	int swap_m = m;

	while (swap_m != 0)
	{
		int z = swap_m;
		swap_m = swap_n % swap_m;
		swap_n = z;
	}

	if (m % n == 0)
	{
		printf("%d", 1);
	}
	else
	{
		printf("%d", n / swap_n);
	}
	return 0;
}