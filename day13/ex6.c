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

/**/
struct timespec work_timer;
double acc_tick,last_tick;
int bLoop = 1;

/**/
_S_MAP_OBJECT gScreenBuffer[2];
_S_MAP_OBJECT gBulletModel;
_S_BULLET_OBJECT gBulletObj;

/**/
int main()
{
    /**/
	set_conio_terminal_mode();
	acc_tick=last_tick=0;

    for(int i = 0 ; i < 2 ; i++)
    {
        map_init(&gScreenBuffer[i]);
        map_new(&gScreenBuffer[i], 35, 18);
    }
    map_init(&gBulletModel);
    map_load(&gBulletModel, "plasma.dat");

    bullet_init(&gBulletObj, 0, 0, 0, &gBulletModel);

    system("clear");

    int ntargetX = 2;
    int ntargetY = 3;
    int nfireX = 24;
    int nfireY = 12;

    double target_x = 14;
    double target_y = 3;
    double center_x = 14;
    double center_y = 7;
    double angle = 0;

    /**/
	while(bLoop) 
    {
		//타이밍처리 
		clock_gettime(CLOCK_MONOTONIC,&work_timer);
		double cur_tick = work_timer.tv_sec + 
			(double)(work_timer.tv_nsec * 1e-9);
		double delta_tick = cur_tick - last_tick;
		last_tick = cur_tick;

		//실시간 입력
		if(kbhit() != 0) 
        {
			char ch = getch();
			if(ch == 'q') 
            {
				bLoop = 0;
				puts("bye~ \r");
			}
		}

        angle += (delta_tick * 45);
        double rad = angle / 180.0 * 3.141592;
        double tx = (target_x - center_x) * cos(rad) - (target_y - center_y) * sin(rad);
        double ty = (target_y - center_y) * cos(rad) + (target_x - center_x) * sin(rad);
        tx += center_x;
        ty += center_y;

		//타이밍 계산 
		acc_tick += delta_tick;
		if(acc_tick > 0.1) 
        {
            //버퍼 체인지
            map_drawTile(&gScreenBuffer[0], 0, 0, &gScreenBuffer[1]);
            map_put(&gScreenBuffer[1], tx, ty, 2);
            map_put(&gScreenBuffer[1], center_x, center_y, 5);
            map_put(&gScreenBuffer[1], target_x, target_y, 1);
            // 버퍼 출력
            gotoxy(0, 0);
            map_dump(&gScreenBuffer[1]);

			acc_tick = 0;
		}
	}
	return 0;
}