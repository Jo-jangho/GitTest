#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    //add 10, 20
    //sub 5, 2
    //mul 4, 3
    //div 8, 2

    char strCmd[128];
    char* ptrTemp;
    char* pCmd;
    int a, b;

    gets(strCmd);

    ptrTemp = strtok(strCmd, " ");
    pCmd = strdup(ptrTemp);
    a = atoi(strtok(NULL,","));
    b = atoi(strtok(NULL,","));

    if(strcmp(ptrTemp, "add") == 0)
    {
        printf("덧셈 : %d", a + b);
    }
    else if(strcmp(ptrTemp, "sub") == 0)
    {
        printf("뺄셈 : %d", a - b);
    }
    else if(strcmp(ptrTemp, "mul") == 0)
    {
        printf("곱셈 : %d", a * b);
    }
    else if(strcmp(ptrTemp, "div") == 0)
    {
        printf("나눗셈 : %d", a / b);
    }

    return 0;
}