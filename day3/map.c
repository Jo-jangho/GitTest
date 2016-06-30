#include <stdio.h>
#include <stdlib.h>
#include "engine2d.h"

#define MAP_WIDTH 60
#define MAP_HEIGHT 50

void setAllMap(int x, int y)
{
    setColor(BLUE, B_BLACK);
    gotoxy(x, y);
    printf("~");
}

void setMountin(int x, int y)
{
    setColor(GREEN, B_BLACK);
    gotoxy(x, y);
    printf("♣");
}

int main(void)
{
    system("clear");

    /**/
    for(int i = 0 ; i < MAP_HEIGHT ; i++)
    {
        for(int j = 0 ; j < MAP_WIDTH ; j++)
        {
            setAllMap(j, i);
        }
    }

    /**/
    for(int i = 0 ; i < MAP_WIDTH - 6 ; i++)
    {
        for(int j = 0 ; j < MAP_HEIGHT - 36 ; j++)
        {
            setMountin(i, j);
        }
        
    }

    setAllMap(60, 50);
    setColor(RESET, RESET);
    return 0;
}