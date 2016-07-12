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

#endif