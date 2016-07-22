#ifndef __RUNGAME_H__
#define __RUNGAME_H__

#define WIDTH 32
#define HEIGHT 8

struct timespec work_timer;
double acc_tick,last_tick;
int bLoop = 1;

typedef struct _S_Player
{
	int m_nPosX;
	int m_nPosY;
	_S_MAP_OBJECT *m_pBody;
}_S_Player;

_S_MAP_OBJECT gMap[3];
_S_MAP_OBJECT gScreenBuffer[2];
_S_MAP_OBJECT gPlayer;

_S_Player gPlayerObject;

void Player_init(_S_Player *pObj, _S_MAP_OBJECT *pBody, int x, int y)
{
    pObj->m_pBody = pBody;
    pObj->m_nPosX = x;
    pObj->m_nPosY = y;
}

void Player_Apply(_S_Player *pObj, double deltaTick, char key_input)
{  
    switch(key_input)
    {
        case 'w':
            if(pObj->m_nPosY > 0)
            {
                pObj->m_nPosY--;
            }
            break;
        case 'a':
            if(pObj->m_nPosX > 0)
            {
                pObj->m_nPosX--;
            }
            break;
        case 's':
            if(pObj->m_nPosY < HEIGHT - 3)
            {
                pObj->m_nPosY++;
            }
            break;
        case 'd':
            if(pObj->m_nPosX < WIDTH - 5)
            {
                pObj->m_nPosX++;
            }
            break;
    }
}

void Player_Draw(_S_Player *pObj, _S_MAP_OBJECT *pBuff)
{
    map_drawTile_trn(pObj->m_pBody, pObj->m_nPosX, pObj->m_nPosY, pBuff);
}

void putTile(_S_MAP_OBJECT *pObj, int sy, int ey, int sx, int ex)
{
    for(int i = sy ; i < ey ; i++)
    {
        for(int j = sx ; j < ex ; j++)
        {
            putchar(pObj->m_pBuf[i * pObj->m_header.m_nWidth + j]);
        }
        printf("\r\n");
    }
}

#endif