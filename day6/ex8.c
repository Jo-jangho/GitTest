#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char cmd[] = "add 100,300";
    char* ptrTemp;
    char a, b;

    ptrTemp = strtok(cmd, " ");

    a = atoi(strtok(NULL, ","));
    b = atoi(strtok(NULL, ","));

    printf("질문에 대한 결과는 %d\n", a + b);

    return 0;
}