#ifndef __BULLET_H__
#define __BULLET_H__

typedef struct
{
    int m_nFSM;
    int m_nStep;
    double m_fPosX;
    double m_fPosY;
    double m_fSpeed;

    _S_MAP_OBJECT *m_pBody;
}_S_BULLET_OBJECT;

void bullet_init(_S_BULLET_OBJECT *pObj, double x, double y, double speed, _S_MAP_OBJECT *pBody)
{
    pObj->m_nFSM = 0;   //  0 : sleep,  1 : active
    pObj->m_nStep = 0;
    pObj->m_fSpeed = speed;
    pObj->m_fPosX = x;
    pObj->m_fPosY = y;
    pObj->m_pBody = pBody;
}

void bullet_apply(_S_BULLET_OBJECT *pObj, double deltaTick)
{
    pObj->m_fPosY -= deltaTick * pObj->m_fSpeed;
    if(pObj->m_fPosY < 0)
    {
        pObj->m_nFSM = 0;
        pObj->m_fSpeed = 0;
    }
}

void bullet_draw(_S_BULLET_OBJECT *pObj, _S_MAP_OBJECT *pMapBuf)
{
    map_drawTile_trn(pObj->m_pBody, (int)pObj->m_fPosX, (int)pObj->m_fPosY, pMapBuf);
}

#endif