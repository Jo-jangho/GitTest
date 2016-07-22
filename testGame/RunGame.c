#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <string.h>
#include <unistd.h>
#include <sys/select.h>
#include <termios.h>

#include "../engine2d/engine2d.h"
#include "../mapEditor/map.h"
#include "RunGame.h"

int main()
{
	set_conio_terminal_mode();
	acc_tick=last_tick = 0;
	system("clear");

	/* 리소스 로딩 */
	map_init(&gMap[0]);
	map_load(&gMap[0], "map1.dat");
	map_init(&gMap[1]);
	map_load(&gMap[1], "map2.dat");
	map_init(&gMap[2]);
	map_load(&gMap[2], "map3.dat");

	map_init(&gPlayer);
    map_load(&gPlayer, "player.dat");

	for(int i = 0 ; i < 2 ; i++)
	{
		map_init(&gScreenBuffer[i]);
    	map_new(&gScreenBuffer[i], WIDTH, HEIGHT);	
	}

	Player_init(&gPlayerObject, &gPlayer, 0, 5);

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
		
		//타이밍 계산 
		acc_tick += delta_tick;
		if(acc_tick > 1.0) 
        {
			map_drawTile(&gScreenBuffer[0], 0, 0, &gScreenBuffer[1]);
			Player_Draw(&gPlayerObject, &gScreenBuffer[1]);

			gotoxy(0, 0);
            printf("--------------------------------\r\n");
            map_dump(&gScreenBuffer[1]);
            printf("--------------------------------\r\n");

			acc_tick = 0;
		}
	}
	return 0;
}