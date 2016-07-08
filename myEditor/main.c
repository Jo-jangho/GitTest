#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern char strCmd[];

void me_exit();
void push();
void insert();
void me_remove();
void change();
void pop();
void delete();
void me_dump();

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
        else if(!strcmp(pTemp, "push"))
        {
            push();
        }
        else if(!strcmp(pTemp, "insert"))
        {
            insert();
        }
        else if(!strcmp(pTemp, "rm"))
        {
            me_remove();
        }
        else if(!strcmp(pTemp, "change"))
        {
            change();
        }
        else if(!strcmp(pTemp, "pop"))
        {
            pop();
        }
        else if(!strcmp(pTemp, "delete"))
        {
            delete();
        }
        else if(!strcmp(pTemp, "dump"))
        {
            me_dump();
        }
    }
    
    return 0;
}