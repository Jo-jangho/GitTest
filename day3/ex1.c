#include <stdio.h>

int main(void)
{
    char c;

    scanf("%c", &c);

/*
    if(c == 'z')
    {
        printf("질럿을 생산합니다.\n");
    }
    else if(c == 'd')
    {
        printf("드라군을 생산합니다.\n");
    }
    else
    {
        printf("잘못된 입력입니다.\n");
    }
*/
    switch(c)
    {
        case 'c':
            printf("캐리어를 생산합니다\n");
        case 'z':
            printf("질럿을 생산합니다\n");
            break;
        case 'd':
            printf("드라군을 생산합니다.\n");
            break;
        default :
            printf("잘못된 입력입니다.\n");
            break;
    }


    return 0;
}