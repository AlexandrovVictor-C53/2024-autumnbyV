
#include<cstdio>
#include<cmath>
int main(int argc, char* argv[])
{
	int k = 0;
	int n = 0;
	int h = 0;
	scanf_s("%d", &n);

	for (int i = 1; i <= n && k == 0; ++i)
	{
		scanf_s("%d", &h);



		if (h <= 437) k = i;
	}


	if (k !=0) printf("Crash %d\n", k);

	else {
		printf("No crash");
	}
	return 0;
}
