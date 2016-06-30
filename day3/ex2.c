#include <stdio.h>

int main(void)
{
    int a = 10;
    while(a >= 0)
    {
        printf("%d\n", a--);
    }
/*
    for(int i = 1 ; i < 10 ; i++)
    {
        for(int j = 2 ; j < 10 ; j++)
        {
            printf("%2d * %2d = %2d", j, i, j * i);
        }
        puts("");
    }*/

    return 0;
}