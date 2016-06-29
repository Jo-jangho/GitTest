#include <stdio.h>
#include <stdlib.h>
#include "engine2d.h"

int main(void)
{
    system("clear");

    setColor(RED, B_YELLOW);
    gotoxy(10, 10);
    printf("Hello World");

    setColor(RESET, RESET);
    return 0;
}