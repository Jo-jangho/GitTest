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
    double angle = 0;
    double my = 0;
    _S_MAP_OBJECT ScreenBuf;
    map_init(&ScreenBuf);
    map_new(&ScreenBuf, 35, 20);

    system("clear");
    gotoxy(0, 0);

    for(int i = 0 ; i < 35 ; i++)
    {
        angle = (double)i * (180 / 35);
        //printf("%f\r\n", sin((angle / 180) * PI));
        my = sin(angle / 180 * PI) * 8.0;
        map_put(&ScreenBuf, i, 10 + my, 1);

        my = cos(angle / 180 * PI) * 8.0;
        map_put(&ScreenBuf, i, 10 + my, 2);
    }

    map_dump(&ScreenBuf);

    return 0;
}