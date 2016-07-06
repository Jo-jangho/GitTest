#include <stdio.h>

int sum(int a, int b)
{
    return a + b;
}

int main(void)
{
    int (*fp)(int, int) = sum;
    
    int r = fp(1, 2);

    printf("%d\n", r);

    return 0;
}