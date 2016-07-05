#include <stdio.h>
#include <string.h>

int ext_sum = 0;

void test()
{
    static int sum = 0;

    sum++;
    ext_sum++;

    printf("%d\n", sum);
}

int main(void)
{
    printf("%d\n", ext_sum);
    test();
    printf("%d\n", ext_sum);
    test();
    printf("%d\n", ext_sum);

    return 0;
}