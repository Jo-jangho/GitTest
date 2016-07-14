#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>
#include <sys/select.h>
#include <termios.h>
#include <math.h>
#include "../mapEditor/map.h"
#include "../engine2d/engine2d.h"

int main(void)
{
    _S_MAP_OBJECT ScreenBuf;

    map_init(&ScreenBuf);
    map_new(&ScreenBuf, 35, 17);

    system("clear");

    gotoxy(0, 0);

    double startX, startY;
    double endX, endY;

    startX = 14;
    startY = 8;
    endX = 31;
    endY = 3;

    map_put(&ScreenBuf, (int)startX, (int)startY, 1);
    map_put(&ScreenBuf, (int)endX, (int)endY, 2);

    // 방향벡터 구하기
    double mx = startX;
    double my = startY;

    double vx = endX - startX;
    double vy = endY - startY;
    double c = sqrt((vx * vx) + (vy * vy));
    vx /= c;
    vy /= c;

    while(1)
    {
        mx += vx * 1.0;
        my += vy * 1.0;
        if( (int)mx == (int)endX && (int)my == (int)endY)
        {
            break;
        }
        map_put(&ScreenBuf, (int)mx, (int)my, 5);
        map_dump(&ScreenBuf);
    }

    return 0;
}

