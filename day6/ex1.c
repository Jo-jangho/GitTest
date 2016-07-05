#include <stdio.h>

int main(void)
{
    int ary[5] = { 1, 2, 3, 4, 5 };
    int ary2[5];
    int* pAry;

    pAry = ary;
    printf("%d, %d\n", pAry[1], *(ary + 1));
    
    return 0;
}