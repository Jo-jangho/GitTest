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
#include "temp_1.h"

int main(void)
{
    /**/
	set_conio_terminal_mode();
	acc_tick=last_tick=0;
    system("clear");

    /**/
    map_init(&gMap);
    map_new(&gMap, WIDTH, HEIGHT);

    map_init(&gScreenBuffer);
    map_new(&gScreenBuffer, WIDTH, HEIGHT);

    map_init(&gPlayer);
    map_load(&gPlayer, "fly.dat");

    map_init(&gMissile);
    map_load(&gMissile, "mis.dat");

    Plane_init(&gPlayerPlane, &gPlayer, WIDTH / 2, HEIGHT - 4);

    int nSize = sizeof(gBullets) / sizeof(_S_BULLET_OBJECT);
    for(int i = 0 ; i < nSize ; i++)
    {
        bullet_init(&gBullets[i], 0, 0, 0, &gMissile);
    }
    
    /**/
	while(bLoop) 
    {
		//타이밍처리 
		clock_gettime(CLOCK_MONOTONIC,&work_timer);
		double cur_tick = work_timer.tv_sec + (double)(work_timer.tv_nsec * 1e-9);
		double delta_tick = cur_tick - last_tick;
		last_tick = cur_tick;

		//실시간 입력
		if(kbhit() != 0)
        {
            char ch = getch();
            if(ch == 'q')
            {
                bLoop = 0;
            }
            else if(ch == 'j')
            {
                bStep = 1;
            }
            gPlayerPlane.fpApply(&gPlayerPlane, delta_tick, ch);
        }

        if(bStep == 1)
        {
            for(int i = 0 ; i < nSize ; i++)
            {
                _S_BULLET_OBJECT *pObj = &gBullets[i];
                if(pObj->m_nFSM == 0)
                {
                    bullet_vector(pObj, 0, 0, gPlayerPlane.m_nPosX, gPlayerPlane.m_nPosY); 
                    pObj->m_nFSM = 1;
                }
            }
        }

        for(int i = 0 ; i < nSize ; i++)
        {
            _S_BULLET_OBJECT *pObj = &gBullets[i];
            if(pObj->m_nFSM == 1)
            {
                bullet_apply(pObj, delta_tick);
            }
        }
            
        //타이밍 계산
        acc_tick += delta_tick;
        if(acc_tick > 0.1)
        {
            map_drawTile(&gMap, 0, 0, &gScreenBuffer);
            gPlayerPlane.fpDraw(&gPlayerPlane, &gScreenBuffer);
            for(int i = 0 ; i < nSize ; i++)
            {
                _S_BULLET_OBJECT *pObj = &gBullets[i];
                if(pObj->m_nFSM == 1)
                {
                    bullet_draw(pObj, &gScreenBuffer);
                }
            }
            gotoxy(0, 0);
            printf("-----------------------------------\r\n");
            map_dump(&gScreenBuffer);
            printf("-----------------------------------\r\n");

            puts("move : w, a, s, d\r");
            puts("fire : j\r");
            puts("quit : q\r");
            
            acc_tick = 0;
        }
	}
	return 0;
}