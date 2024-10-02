#include <iostream>
#include <math.h>

int main(int argc, char* argv[])
{
	int x1 = 0;
	int y1 = 0;
	int r1 = 0;
	int x2 = 0;
	int y2 = 0;
	int r2 = 0;
	int r  = 0;

	scanf_s("%d", &x1);
	scanf_s("%d", &y1);
	scanf_s("%d", &r1);
	scanf_s("%d", &x2);
	scanf_s("%d", &y2);
	scanf_s("%d", &r2);

	r = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	if (r1 + r2 >= r && r + r2 >= r1 && r + r1 >= r2) {

		printf("YES");
	}
	else {
		printf("NO");
	}
	return 0;
}