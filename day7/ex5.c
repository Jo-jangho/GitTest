#include <stdio.h>

int doit(int (*fp)(int, int), int a, int b)
{
    return fp(a, b);
}

int sum(int a, int b)
{
    return a + b;
}

int sub(int a, int b)
{
    return a - b;
}

int main(void)
{
    int (*ary_fp[2])(int, int) = { sum, sub };

    /*printf("%d\n", doit(sum, 3, 2));
    printf("%d\n", doit(sub, 3, 2));*/

    for(int i = 0 ; i < 2 ; i++ )
    {
        printf("%d\n", doit(ary_fp[i], 3, 2));
    }

    return 0;
}