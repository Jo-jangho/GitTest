#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/select.h>
#include <termios.h>
#include "engine2d.h"

int main(void)
{
    system("clear");

    char cmd;
    int nXpos = 10, nYpos = 10, bLoop = 1;
    int orc_xPos = 10, orc_yPos = 10;

    drawMyCar(nXpos, nYpos);

    //drawMyBox(orc_xPos, orc_yPos, 4, 4, BLUE, B_BLUE);

    while(bLoop)
    {
        system("clear");
        usleep(100000);

        if(kbhit() != 0)
        {
            cmd = getch();
        }

        switch(cmd)
        {
            case 'w':
                nYpos -= 1;
                break;
            case 's':
                nYpos += 1;
                break;
            case 'a':
                nXpos -= 1;
                break;
            case 'd':
           	    nXpos += 1;
                break;
            case 'q':
                bLoop = 0;
                break;
        }
        
        // 플레이어 
        drawMyCar(nXpos, nYpos);
        
        
        
    }
   
    drawMyBox(0, 50, 1, 80 , BLUE, B_CYAN);

    setColor(RESET, RESET);

    return 0;
}

/*
if(orc_xPos > nXpos)
        {
            orc_xPos -= 1;
        }
        else if(orc_xPos < nXpos)
        {
            orc_xPos += 1;
        }
        else
        {
            if(orc_yPos > nYpos)
            {
                orc_yPos -= 1;
            }
            else if(orc_yPos < nYpos)
            {
                orc_yPos += 1;
            }
            else
            {
                gotoxy(30, 30);
                printf("패배");
                //bLoop = 0;
            }
        }

        // 오크 
        drawMyBox(orc_xPos, orc_yPos, 3, 3, BLUE, B_BLUE);
        */