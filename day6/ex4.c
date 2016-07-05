#include <stdio.h>
#include <string.h>

int main(void)
{
    char* pStr = "Hello World";
    char strTemp[128];

    strcpy(strTemp, pStr);

    strTemp[0] = 'R';
    printf("원본 %s \n", pStr);

    printf("%s 을 복사 했습니다. \n", strTemp);

    printf("문자열의 길이는 %d\n", strlen(strTemp));

    int cmp = strcmp(strTemp, pStr);

    printf("%d \n", cmp);

    char* pStr2 = ",hi world";

    strcat(pStr, pStr2);

    printf("%s \n", strTemp);

    return 0;
}