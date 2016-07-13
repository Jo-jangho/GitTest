#ifndef __TEMP_1_H__
#define __TEMP_1_H__

#include "../engine2d/engine2d.h"
#include "../mapEditor/map.h"
#include "bullet.h"

#define WIDTH 35
#define HEIGHT 16

typedef struct
{
    int m_nPosX;
    int m_nPosY;
    _S_MAP_OBJECT *m_pBody;
}_S_Plane;

struct timespec work_timer;
double acc_tick, last_tick;
int bLoop = 1;

int mis_posX;
int mis_posY;

//  게임 오브젝트 선언
_S_MAP_OBJECT gMap;
_S_MAP_OBJECT gScreenBuffer;
_S_MAP_OBJECT gPlayer;
_S_MAP_OBJECT gMissile;

_S_Plane gPlayerPlane;
_S_BULLET_OBJECT gBullets[32];

void Plane_init(_S_Plane *pObj, _S_MAP_OBJECT *pBody, int x, int y)
{
    pObj->m_pBody = pBody;
    pObj->m_nPosX = x;
    pObj->m_nPosY = y;
}

void Plane_Apply(_S_Plane *pObj, double deltaTick, char key_input)
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

void Plane_Draw(_S_Plane *pObj, _S_MAP_OBJECT *pBuff)
{
    map_drawTile_trn(pObj->m_pBody, pObj->m_nPosX, pObj->m_nPosY, pBuff);
}


#endif