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
            else if(ch == 'j')
            {
                bullet_vector(&gBulletObj, nfireX, nfireY, ntargetX, ntargetY);
            }
            else if(ch == 'a')
            {
                ntargetX--;
            }
            else if(ch == 'd')
            {
                ntargetX++;
            }
            else if(ch == 'w')
            {
                ntargetY--;
            }
            else if(ch == 's')
            {
                ntargetY++;
            }
		}

        bullet_apply(&gBulletObj, delta_tick);

		//타이밍 계산 
		acc_tick += delta_tick;
		if(acc_tick > 0.1) 
        {
            //버퍼 체인지
            map_drawTile(&gScreenBuffer[0], 0, 0, &gScreenBuffer[1]);
            bullet_draw(&gBulletObj, &gScreenBuffer[1]);
            // 버퍼 출력
            gotoxy(0, 0);
            map_put(&gScreenBuffer[1], nfireX, nfireY, 1);
            map_put(&gScreenBuffer[1], ntargetX, ntargetY, 5);
            map_dump(&gScreenBuffer[1]);

			acc_tick = 0;
		}
	}
	return 0;
}