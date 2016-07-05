#include <stdio.h>

int main(void)
{
    char aStr[] = "world";
    char *pStr = "hello";

    printf("%s %s \n", aStr, pStr);

    pStr = aStr;

    printf("%s \n", pStr);

    aStr = pStr;    //배열에 포인터 주소값을 넣을 수 없음

    return 0;
}