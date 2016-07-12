#include <stdio.h>

void change(int *a, int *b)
{
    int *c = a;
    a = b;
    b = c;
}

int main(void)
{
    int a = 10;
    int b = 20;

    printf("%d %d\n", a, b);
    
    change(&a, &b);

    printf("%d %d\n", a, b);

    return 0;
}