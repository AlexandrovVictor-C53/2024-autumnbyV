#include <stdio.h>

int main() {
	int n;

	scanf_s("%d", &n);

	printf("The next number for the number %d is %d.\n", n, n + 1);
	printf("The previous number for the number %d is %d.\n", n, n - 1);

	return 0;
}