#include<iostream>

int main(int argc, char* argv[])
{
	int a = 0;
	scanf_s("%d", &a);

	printf("%d %d %d", (a / 3) / 2, (a / 3) * 2, (a / 3) / 2);

	return EXIT_SUCCESS;
}