#include<cstdio>
#include<cmath>
int main(int argc, char* argv[])
{
	int m = 0;
	int n = 0;
	int k = 0;
	scanf_s("%d", &k);

	for (int i = 1; i <= k; ++i)
	{
	
		scanf_s("%d", &n);
		scanf_s("%d", &m);
		printf("%d\n", 19 * m + (n + 239) * (n + 366) / 2);
	}
	return 0;
}