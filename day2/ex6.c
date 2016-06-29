#include <stdio.h>

int main(void)
{
    int num1;

    printf("정수를 입력하세요 : ");
    scanf("%d", &num1);

    if( 5 < num1 && num1 < 9 )
        printf("5보다 크고 9보다 작습니다.");

    return 0;
}