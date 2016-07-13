#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>
#include <sys/select.h>
#include <termios.h>

#include "../engine2d/engine2d.h"
#include "../mapEditor/map.h"

struct timespec work_timer;
double acc_tick,last_tick;
int bLoop = 1;

_S_MAP_OBJECT gScreenBuffer;
_S_MAP_OBJECT gPlayer;

int main()
{
	set_conio_terminal_mode();
	acc_tick=last_tick=0;
    int nHight = 16;
    int nWidth = 35;
    int player_posX = nWidth / 2;
    int player_posY = nHight - 4;

    map_init(&gScreenBuffer);
    map_new(&gScreenBuffer, nWidth, nHight);

    map_init(&gPlayer);
    map_load(&gPlayer, "fly.dat");

	while(bLoop) 
    {
		//타이밍처리 
		clock_gettime(CLOCK_MONOTONIC,&work_timer);
		double cur_tick = work_timer.tv_sec + (double)(work_timer.tv_nsec * 1e-9);
		double delta_tick = cur_tick - last_tick;
		last_tick = cur_tick;

        system("clear");

		//실시간 입력
		if(kbhit() != 0)
        {
            char ch = getch();
            if(ch == 'q')
            {
                bLoop = 0;
            }
            else if(ch == 'w')
            {
                player_posY--;
            }
            else if(ch == 'a')
            {
                player_posX--;
            }
            else if(ch == 's')
            {
                player_posY++;
            }
            else if(ch == 'd')
            {
                player_posX++;
            }

            map_drawTile(&gPlayer, player_posX - 3, player_posY, &gScreenBuffer);

            //타이밍 계산
            acc_tick += delta_tick;
            if(acc_tick > 1.0)
            {
                gotoxy(0, 0);
                puts("-------------------------------/r");
                map_dump(&gScreenBuffer);
                puts("-------------------------------/r");

                puts("move : w, a, s, d\r");
                puts("quit : q\r");
                
                acc_tick = 0;
            }
        }
	}
	return 0;
}