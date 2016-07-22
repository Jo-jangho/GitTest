#include "temp_1.h"
#include "bullet.h"

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
        bullet_init(&gBullets[i], gPlayerPlane.m_nPosX, gPlayerPlane.m_nPosY, 0, &gMissile);
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
                for(int i = 0 ; i < nSize ; i++)
                {
                    _S_BULLET_OBJECT *pObj = &gBullets[i];
                    if(pObj->m_nFSM == 0)
                    {
                        pObj->m_nFSM = 1;
                        pObj->m_fPosX = (double)gPlayerPlane.m_nPosX;
                        pObj->m_fPosY = (double)gPlayerPlane.m_nPosY;
                        pObj->m_fSpeed = 3.0;
                        break;
                    }
                }
            }
            Plane_Apply(&gPlayerPlane, delta_tick, ch);
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
            Plane_Draw(&gPlayerPlane, &gScreenBuffer);
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