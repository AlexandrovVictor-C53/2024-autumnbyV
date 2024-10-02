#include<iostream> 
#include<math.h> 
int main(int argc, char* argv[]) {
    int x = 0;
    int y = 0;
    scanf_s("%d", &x);
    scanf_s("%d", &y);
    if (x == 1 and y == 1)
       printf("0");
    else
        if (x == y) {
           printf("2");
        }
        else
           printf("1");
    return 0;
}