#include<cstdio>

int main(int argc, char* argv[])
{
	int x[1001];
	int i = 0;
	int n = 0;
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int y = 0;

	scanf_s("%d", &i);
	scanf_s("%d", &n);
	scanf_s("%d", &n);
	scanf_s("%d", &a);
	scanf_s("%d", &b);
	scanf_s("%d", &c);
	scanf_s("%d", &d);
	scanf_s("%d", &y);

	
	for (i = 1;i <= n;i++) {
		x[i] = i;
	}
	//...
	

	for (i = 1;i <= n;i++) {
		printf("%d", x[i]);
		printf(" ");
	}

	return 0;
}