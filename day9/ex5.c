#include <stdio.h>

int main(void)
{
    int a = 3;
    int b = 2;
    int max;

    max = (a > b) ? a : b;
    printf("%d\n", max);

    return 0;
}