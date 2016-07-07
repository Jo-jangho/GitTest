#include <stdio.h>

int main(void)
{
    FILE* pFile = fopen("ex1.c", "r");

    if(pFile == NULL)
    {
        puts("open failed");
    }
    else
    {
        puts("open success");

        while(1)
        {
            char ch = fgetc(pFile);        
            
            if(ch == EOF) break;

            putchar(ch);
        }
    }

    return 0;
}