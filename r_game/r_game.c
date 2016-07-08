#include "engine2d.h"
#include "r_game.h"

/**/
static int nFSM = 0;
static int nStep = 0;

int bLoop = 1;
double acc_tick,last_tick;
struct timespec work_timer;

/**/
void rg_playGame(double delta_tick)
{
	//사용자 입력처리
	if(kbhit() != 0) 
	{
		char ch = getch();
		if(ch == 'q') 
		{
			bLoop = 0;
		}
		else if(ch == 'a') 
		{
			if(screen_buffer[56] != 2)
			{
				car_posx -= 1;
			}
		}
		else if(ch == 'd') 
		{
			if(screen_buffer[63] != 2)
			{
				car_posx += 1;
			}
		}
	}

	//바위 움직이기
	rock_acc_tick += delta_tick;
	if(rock_acc_tick > 0.2)
	{
		rock_acc_tick = 0;
		rock_pos_y += 1;
		if(rock_pos_y > 8)
		{
			rock_pos_y = 0;
			rock_pos_x = rand() % 7;
		}
	}

	//게임로직 (판정)
	if(rock_pos_y == car_posy && rock_pos_x == car_posx)
	{
		//bLoop = 0;
		system("clear");
		gotoxy(1, 1);
		setColor(RED, B_BLACK);
		printf("Game Over!\n");

		sleep(1);

		nFSM = 0;
	}

	//버퍼초기화 
	for(int i = 0 ; i < 64 ; i++) 
	{
		screen_buffer[i] = 0;
	}

	//자동차 그리기
	screen_buffer[ car_posy * 8 + car_posx] = 2;

	//바위 그리기
	screen_buffer[ rock_pos_y * 8 + rock_pos_x] = 1;

	acc_tick += delta_tick;
	if(acc_tick > 0.1 || bLoop == 0) 
	{
		acc_tick = 0;
		
		//랜더링
		drawGame(screen_buffer, 8, 8);
	}
}

void rg_apply_mainTktle()
{	
	//사용자 입력처리
	switch(nStep)
	{
		case 0:
			puts("press to start");
			nStep = 1;
			break;
		case 1:
			if(kbhit() != 0) 
			{
				system("clear");
				char ch = getch();
				nFSM = 1;
				nStep = 0;
			}
			break;
	}
}

int main(void)
{
	set_conio_terminal_mode();
	acc_tick = last_tick = 0;
	system("clear");

	srand(time(NULL));

	car_posy = 7;
	car_posx = 3;
	rock_pos_x = rand() % 7;

	while(bLoop) 
	{
		//타이밍처리 
		clock_gettime(CLOCK_MONOTONIC,&work_timer);
		double cur_tick = work_timer.tv_sec + (double)(work_timer.tv_nsec * 1e-9);
		double delta_tick = cur_tick - last_tick;
		last_tick = cur_tick;

		if(nFSM == 0)		// 타이틀 메뉴 상태
		{
			rg_apply_mainTktle();
		}
		else if(nFSM == 1)	// 게임상태
		{
			rg_playGame(delta_tick);
		}
		else
		{

		}
	}
		
	return 0;
}
