#include <stdio.h>

int main(void)
{
     char str[80] = "dream";

     printf("%s \n", str);

     int nCount = 0;
     while(str[++nCount] != 0)  {}

     printf("배열에 저장된 문자열의 길이 : %d\n", nCount);

    return 0;
}