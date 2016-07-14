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

#include "../engine2d/engine2d.h"
#include "../mapEditor/map.h"
#include "bullet.h"

#define PI 3.141592

// a : 180 = b : PI
// b = a / 180 * PI

int main(void)
{
    _S_MAP_OBJECT ScreenBuf;
    map_init(&ScreenBuf);
    map_new(&ScreenBuf, 70, 40);

    system("clear");
    gotoxy(0, 0);

    double targetX = 14;
    double targetY = 4;

    double centerX = 24;
    double centerY = 18;

    map_put(&ScreenBuf, targetX, targetY, 5);
    map_put(&ScreenBuf, centerX, centerY, 5);

    for(int i = 0 ; i < 360 ; i++)
    {
        double rad = ((double)i) / 180.0 * PI;
        double tx = (targetX - centerX) * cos(rad) - (targetY - centerY) * sin(rad);
        double ty = (targetY - centerY) * cos(rad) + (targetX - centerX) * sin(rad);

        tx += centerX;
        ty += centerY;

        map_put(&ScreenBuf, tx, ty, 1);
    }
    
    map_dump(&ScreenBuf);

    return 0;
}