

#include<cstdio>
#include<math.h>
int main(int argc, char* argv[])
{
	int n = 0;
	int v = 0;
	int s = 0;
	int muzhP = 0;
	int b = -1;

	scanf_s("%d", &n);

	for (int i = 1; i <= n; ++i)
	{
		scanf_s("%d", &v);
		scanf_s("%d", &s);

		if (s !=0 && v > muzhP) {
			muzhP = v;
			b = i;
		}
	}
	printf("%d", b);
	return 0;
}

