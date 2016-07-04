#include <stdio.h>

void exchange(int *pA, int *pB)
{
    int temp;

    temp = *pA;
    *pA = *pB;
    *pB = temp;
}

int main(void)
{
    int a = 10, b = 20;

    printf(" 바꾸기 전의 두 변수의 값 : %d, %d\n", a, b);

    exchange(&a, &b);

    printf(" 바꾼 후의 두 변수의 값 : %d, %d\n", a, b);

    return 0;
}imiii