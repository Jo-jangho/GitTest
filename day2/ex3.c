#include <stdio.h>

int main(void)
{
    char name[10];
    int index;

    printf("출력 할 인덱스값을 적으시오 : ");
    scanf("%d", &index);

    printf("출력 할 문자열을 적으시오 : ");
    scanf("%s", name);

    printf("\n %c %s %d \n", name[index], name, name[index]);

    return 0;
}