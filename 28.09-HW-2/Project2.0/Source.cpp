#include<iostream> 

using namespace std;

int main() {
    int x, y;
    scanf_s("%d", &x);
    scanf("%d", &y);
    if (x == 1 and y == 1)
        cout << 0;
    else
        if (x == y) {
            cout << 2;
        }
        else
            cout << 1;
    return 0;
}