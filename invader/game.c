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
#include "bullet.h"
#include "alien.h"
#include "temp_1.h"
#include "game.h"

int main(void)
{    
	while(bLoop) 
    {
		//타이밍처리 
		clock_gettime(CLOCK_MONOTONIC,&work_timer);
		double cur_tick = work_timer.tv_sec + (double)(work_timer.tv_nsec * 1e-9);
		double delta_tick = cur_tick - last_tick;
		last_tick = cur_tick;

        if(nFSM == 0) //타이틀 메뉴 상태 
		{ 
			switch(nStep)
            {
                case 0:
                    game_init();
                    //setColor(YELLOW, B_MAGENTA);
                    puts("========================press to start========================");
                    setColor(RESET, RESET);
                    nStep = 1;
                    break;
                case 1:
                    if(kbhit() != 0) 
                    {
                        if(nStep == 1)
                        {
                            system("clear");
                        }
                        char ch = getch();
                        nFSM = 1;
                        nStep = 0;
                    }
                    break;
            }
		}
		else if(nFSM ==1 ) //게임상태... 
		{
			game_paly(delta_tick);
        }
    }
	return 0;
}