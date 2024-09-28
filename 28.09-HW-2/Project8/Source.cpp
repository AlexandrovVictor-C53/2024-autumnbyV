#include <stdio.h>
#include <math.h>
int main(argc, char* argv[]);
{
    int number1 = 0;
    int number2 = 0;

    scanf_s("%d", &number1);
    scanf_s("%d", &number2);

    if (number1 < number2) {

        int temp = number1;
        number1 = number2;
        number2 = temp;
    }

    if (number1 == 1 || number2 == 1) {
        printf("%d\n", number1 * number2 * 4);
    }
    else {
        int result = (number2 + 2) * number1 + number2 * (number1 + 2);
        if (number1 % 2 == 1 && number2 % 2 == 1) {
            result -= 2;
        }
        printf("%d\n", result);
    }

    return 0;
}