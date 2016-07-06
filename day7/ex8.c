#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int a;
    int* ip;

    ip = (int *)malloc(sizeof(int));

    *ip = 10;

    printf("%d\n", *ip);

    free(ip);

    return 0;
}