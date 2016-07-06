#include <stdio.h>

void ary_prn(int (*ap)[4])
{
    for(int i = 0 ; i < 3 ; i++)
    {
        for(int j = 0 ; j < 4 ; j++)
        {
            printf("%5d", ap[i][j]);
        }
        puts("");
    }
}

int main(void)
{
    int ary[3][4] = {
        { 1, 2, 3, 4 },
        { 5, 6, 7, 8 },
        { 9, 10, 11, 12 }
    };
    int (*ap)[4];
    
    ap = ary;

    ary_prn(ap);

    return 0;
}