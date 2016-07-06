#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int* ip;
    int nCount = 0;
    int sum = 0;

    puts("입력 할 데이터 수.");
    scanf("%d", &nCount);

    ip = (int *)malloc(sizeof(int) * nCount);

    for(int i = 0 ; i < nCount ; i++)
    {
        printf("데이터를 입력하세요(%d / %d) : ", i + 1, nCount);
        scanf("%d", &(ip[i]));
    }

    for(int i = 0 ; i < nCount ; i++)
    {
        sum += ip[i];
    }

    printf("%d\n", sum);

    free(ip);

    return 0;
}