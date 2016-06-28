#include <stdio.h>
#include <stdlib.h>

void line();

int main(void)
{
    system("clear");
    /*
    printf("\x1b[3;3f");
    printf("Hello");

    printf("\x1b[5;2f");
    printf("World");*/

    for(int i = 0 ; i < 20 ; i++)
    {
        printf("%c[%d;20f", 0x1b, i);
        printf("||\n");
    }

    printf("\x1b[20;0f");
    printf("====================\n");

    return 0;
}