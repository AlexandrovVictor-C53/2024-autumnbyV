#include <stdio.h>;
#include <math.h>;


int main() {
	int x1 = 0;
	int y1 = 0;
	int r1 = 0;

	int x2 = 0;
	int y2 = 0;
	int r2 = 0;

	scanf_s("%d", &x1);
	scanf_s("%d", &y1);
	scanf_s("%d", &r1);

	scanf_s("%d", &x2);
	scanf_s("%d", &y2);
	scanf_s("%d", &r2);


	if ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) < (r2 + r1) * (r2 + r1)) {
		printf("YES");
	}
	else {
		printf("NO");
	}
	return 0; 
}


// if (((x1 - x2) + (y1 - y2)) * ((x1 - x2) + (y1 - y2)) == (r2 - r1) * (r2 - r1)) {
#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int x1, y1, r1, x2, y2, r2;
	double r;
	cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
	r = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	if (r1 + r2 >= r && r + r2 >= r1 && r + r1 >= r2)
		cout << "YES";
	else
		cout << "NO";
	return 0;
}