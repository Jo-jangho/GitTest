#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <string.h>
#include <unistd.h>
#include <sys/select.h>
#include <termios.h>
#include <math.h>

#include "../engine2d/engine2d.h"
#include "../mapEditor/map.h"
#include "r_game.h"

int main(void)
{
	set_conio_terminal_mode();
	acc_tick = last_tick = 0;
	system("clear");

	srand(time(NULL));

	while(bLoop) 
	{
		//타이밍처리 
		clock_gettime(CLOCK_MONOTONIC,&work_timer);
		double cur_tick = work_timer.tv_sec + (double)(work_timer.tv_nsec * 1e-9);
		double delta_tick = cur_tick - last_tick;
		last_tick = cur_tick;

		if(nFSM == 0) //타이틀 메뉴 상태 
		{ 
			rg_apply_mainTitle();
		}
		else if(nFSM ==1 ) //게임상태... 
		{
			rg_PlayGame(delta_tick);
		}
		else {
		}

	}
		
	return 0;
}
