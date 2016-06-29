#include <stdio.h>

int main(void)
{
    printf("char 형의 크기 : %d\n", sizeof(char));
    printf("short 형의 크기 : %d\n", sizeof(short));
    printf("int 형의 크기 : %d\n", sizeof(int));
    printf("long 형의 크기 : %d\n", sizeof(long));
    printf("float 형의 크기 : %d\n", sizeof(float));
    printf("double 형의 크기 : %d\n", sizeof(double));
    printf("long double 형의 크기 : %d\n", sizeof(long double));

    return 0;
}