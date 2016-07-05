#include <stdio.h>
#include <string.h>

int main(void)
{
    char* pStrCmd = "move position 123, 56";

    char* ptr = strstr(pStrCmd, "position");

    printf("%s \n", ptr);

    char pStrTemp[128];

    strncpy(pStrTemp, pStrCmd, 4);

    printf("%s \n", pStrTemp);

    char* pStrClone;

    pStrClone = strdup(pStrCmd);

    pStrCmd[0] = 'n';

    printf("%s \n", pStrClone);
    printf("%s \n", pStrCmd);

    return 0;
}