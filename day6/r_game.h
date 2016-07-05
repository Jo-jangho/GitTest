#ifndef __RGAME_H__
#define __RGAME_H__

char screen_buffer[64] = {0,};

double rock_acc_tick;
int rock_pos_x, rock_pos_y;

int car_posx,car_posy;

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
}

#endif