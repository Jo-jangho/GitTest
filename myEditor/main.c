#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void apply(char *);

int main(void)
{
    int bLoop = 1;
    puts("MyEditor veersion 1.0");
    while(bLoop)
    {
        char strCmd[128];
        gets(strCmd);

        char* pTemp = strtok(strCmd, " ");

        if(!strcmp(pTemp, "exit"))
        {
            bLoop = 0;
        }
        else
        {
            apply(pTemp);
        }
    }
    
    return 0;
}