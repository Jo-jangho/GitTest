#include <stdio.h>

int main(void)
{
    int n;          //switch 입력
    int num1, num2; // 계산 해야 할 정수
    int result;     // 결과 값

    puts("1. 더하기");
    puts("2. 빼기");
    puts("3. 곱하기");
    puts("4. 나누기");
    puts("5. 나머지");
    
    printf("메뉴를 선택 해 주세요 : ");
    scanf("%d", &n);

    printf("두 정수를 입력 해 주세요 : ");
    scanf("%d %d", &num1, &num2);

    switch(n)
    {
        case 1:
            result = num1 + num2;
            break;
        case 2:
            result = num1 - num2;
            break;
        case 3:
            result = num1 * num2;
            break;
        case 4:
            result = num1 / num2;
            break;
        case 5:
            result = num1 % num2;
            break; 
    }

    printf("결 과 값 : %3d", result);

    return 0;
}