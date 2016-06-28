#include <stdio.h>

int main(void)
{
    int num = 0;

    scanf("%d",&num);

    for(int i = 0 ; i < num ; i++)
    {
        for(int j = num ; j > i ; j--)
        {
            printf(" ");
        }
        for(int j = 0 ; j <= i * 2 ; j++)
        {
            printf("*");
        }
        puts("");
    }

    return 0;
}