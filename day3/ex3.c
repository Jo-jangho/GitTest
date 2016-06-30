#include <stdio.h>
#include <stdlib.h>
#include "engine2d.h"

void drawMyBox(int x_pos, int y_pos)
{
    int ix, iy;
    ix = 1;
    iy = 1;

    setColor(BLACK, B_GREEN);

    while(ix <= 8)
    {
        iy = 1;
        while(iy <= 4)
        {
            gotoxy(ix + x_pos, iy + y_pos);
            printf(" ");
            iy++;

        }
        setColor(BLACK, B_GREEN + ix);
        ix++;

    }
    setColor(RESET, RESET);
}

int main(void)
{
    system("clear");

    drawMyBox(5, 5);
    
    setColor(BLACK, B_BLUE);
    gotoxy(0, 20);
    printf("                                      ");

    setColor(RESET, RESET);

    return 0;
}