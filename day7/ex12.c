#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int bLoop = 1;
    char* strLine[128] = {0,};
    int nTailIndex = 0;

    while(bLoop)
    {
        char* pTemp;
        char* pstr;
        char strCmd[128];
        gets(strCmd);

        pTemp = strtok(strCmd, " ");

        if(!strcmp(pTemp, "exit"))
        {
            bLoop = 0;
        }
        else if(!strcmp(pTemp, "push"))
        {
            pTemp = strtok(NULL, " ");

            pstr = (char *)malloc(strlen(pTemp) + 1);
            strcpy(pstr, pTemp);

            strLine[nTailIndex++] = pstr;
        }
        else if(!strcmp(pTemp, "insert"))
        {
            //insert 2 hello
            int nIdx = atoi(strtok(NULL, " "));
            pTemp = strtok(NULL, " ");

            pstr = (char *)malloc(strlen(pTemp) + 1);
            strcpy(pstr, pTemp);

            for(int i = nTailIndex ; i > nIdx ; i--)
            {
                strLine[i] = strLine[i - 1];
            }

            strLine[nIdx] = pstr;
            nTailIndex++;
        }
        else if(!strcmp(pTemp, "rm"))
        {
            //rm 1
            int nIdx = atoi(strtok(NULL, " "));
            pTemp = strtok(NULL, " ");

            free(strLine[nIdx]);
            for(int i = nIdx ; strLine[i] != 0x00 ; i++)
            {
                strLine[i] = strLine[i + 1];
            }
            strLine[nTailIndex--] = 0x00;
        }
        else if(!strcmp(pTemp, "change"))
        {
            //remove 2 hello
            int nIdx = atoi(strtok(NULL, " "));
            pTemp = strtok(NULL, " ");

            strcpy(strLine[nIdx], pTemp);
        }
        else if(!strcmp(pTemp, "pop"))
        {
            free(strLine[nTailIndex]);
            strLine[--nTailIndex] = 0x00;
        }
        else if(!strcmp(pTemp, "delete"))
        {
            free(strLine[0]);
            for(int i = 0 ; strLine[i] != 0x00 ; i++)
            {
                strLine[i] = strLine[i + 1];
            }
            strLine[nTailIndex--] = 0x00;
        }
        else if(!strcmp(pTemp, "dump"))
        {
            puts("====================================");
            for(int i = 0 ; strLine[i] != 0x00 ; i++)
            {
                puts(strLine[i]);
            }
            puts("====================================");
        }
    }
    
    return 0;
}