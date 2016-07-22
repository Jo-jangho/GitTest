#ifndef __RGAME_H__
#define __RGAME_H__

/**/
static int nFSM = 0;
static int nStep = 0;
char screen_buffer[64] = {0,};

int bLoop = 1;
double acc_tick,last_tick;
struct timespec work_timer;

double rock_acc_tick;
double rock2_acc_tick;
double rock3_acc_tick;
double score_acc_tick;

int car_posx,car_posy;
int score = 0;

typedef struct
{
    int m_posX;
    int m_posY;
}Rock;

/**/
Rock rock1;	
Rock rock2; 
Rock rock3;

/**/
void drawGame(char* pBuf, int mx, int my)
{
    //랜더링 
    gotoxy(1,1);
    int x, y;
    for(y = 0 ; y < my ; y++)
    {
        for(x = 0 ; x < my ; x++) 
        {
            switch( pBuf[ mx * y + x ]) 
            {
                case 0:
                    putchar('.');
                    break;
                case 1:
                    putchar('#');
                    break;
                case 2:
                    putchar('A');
                    break;
            }
        }
        printf("\r\n");
    }
    printf("\nScore : %d\n", score);
}

/**/
void Init()
{
	car_posy = 7;
	car_posx = 3;

	rock1.m_posX = rand() % 7;
	rock1.m_posY = 0;	
	rock2.m_posX = rand() % 7;
	rock2.m_posY = 0;
	rock3.m_posX = rand() % 7;
	rock3.m_posY = 0;

	score = 0;

	setColor(RESET, RESET);
}

/**/
void rg_PlayGame(double delta_tick)
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

	//버퍼초기화 
	for(int i = 0 ; i < 64 ; i++) 
	{
		screen_buffer[i] = 0;
	}

	//자동차 그리기
	screen_buffer[ car_posy * 8 + car_posx] = 2;

	//바위 그리기
	screen_buffer[ rock1.m_posY * 8 + rock1.m_posX] = 1;
	screen_buffer[ rock2.m_posY * 8 + rock2.m_posX] = 1;
	screen_buffer[ rock3.m_posY * 8 + rock3.m_posX] = 1;

	//점수
	score_acc_tick += delta_tick;
	if(score_acc_tick > 1.0 || bLoop == 0) 
	{
		score_acc_tick = 0;
		score++;
	}

	acc_tick += delta_tick;
	if(acc_tick > 0.1 || bLoop == 0) 
	{
		acc_tick = 0;
		
		//랜더링
		drawGame(screen_buffer, 8, 8);
	}


	//바위 움직이기
	rock_acc_tick += delta_tick;
	if(rock_acc_tick > 0.3)
	{
		rock_acc_tick = 0;
		rock1.m_posY += 1;
		if(rock1.m_posY >= 8)
		{
			rock1.m_posY = 0;
			rock1.m_posX = rand() % 7;
		}
	}

	rock2_acc_tick += delta_tick;
	if(rock2_acc_tick > 0.5)
	{
		rock2_acc_tick = 0;
		rock2.m_posY += 1;
		if(rock2.m_posY >= 8)
		{
			rock2.m_posY = 0;
			rock2.m_posX = rand() % 7;
		}
	}

	rock3_acc_tick += delta_tick;
	if(rock3_acc_tick > 0.7)
	{
		rock3_acc_tick = 0;
		rock3.m_posY += 1;
		if(rock3.m_posY >= 8)
		{
			rock3.m_posY = 0;
			rock3.m_posX = rand() % 7;
		}
	}

	//게임로직 (판정)
	if(rock1.m_posY == car_posy && rock1.m_posX == car_posx)
	{
		system("clear");
		gotoxy(1, 1);
		setColor(RED, B_BLACK);
		printf("Game Over!\r\n");

		setColor(YELLOW, B_BLACK);
		printf("Score : %d\r\n", score);

		sleep(1);
		nFSM = 0;
	}
	else if(rock2.m_posY == car_posy && rock2.m_posX == car_posx)
	{
		system("clear");
		gotoxy(1, 1);
		setColor(RED, B_BLACK);
		printf("Game Over!\r\n");

		setColor(YELLOW, B_BLACK);
		printf("Score : %d\r\n", score);

		sleep(1);
		nFSM = 0;
	}
	else if(rock3.m_posY == car_posy && rock3.m_posX == car_posx)
	{
		system("clear");
		gotoxy(1, 1);
		setColor(RED, B_BLACK);
		printf("Game Over!\r\n");

		setColor(YELLOW, B_BLACK);
		printf("Score : %d\r\n", score);

		sleep(1);
		nFSM = 0;
	}	
}

void rg_apply_mainTitle()
{	
	//사용자 입력처리
	switch(nStep)
	{
		case 0:
			Init();
			puts("press to start");
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

#endif