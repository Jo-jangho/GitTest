#ifndef __AREA_H__
#define __AREA_H__

typedef struct _S_AREA
{
    char *m_szName;
    struct _S_AREA *node[8];

    void (*pfDraw)(struct _S_AREA *);
    struct _S_AREA* (*pfFind)(struct _S_AREA *, const char *);
}_S_AREA;

void area_init(_S_AREA *pObj);
void area_draw(_S_AREA *pObj);
_S_AREA *area_find(_S_AREA *pObj, const char *area_name);

void area_init(_S_AREA *pObj)
{
    for(int i = 0 ; i < 8 ; i++)
    {
        pObj->node[i] = NULL;
    }

    pObj->pfDraw = area_draw;
    pObj->pfFind = area_find;
}

void area_draw(_S_AREA *pObj)
{
    printf("당신은 현재 %s에 있습니다.\r\n", pObj->m_szName);
}

_S_AREA *area_find(_S_AREA *pObj, const char *area_name)
{
    for(int i = 0 ; i < 8 ; i++)
    {
        _S_AREA *pArea = pObj->node[i];
        if(pObj->node[i] != NULL)
        {
            if(strcmp(area_name, pArea->m_szName) == 0 )
            {
                return pArea;
            }
        }
    }

    return NULL;
}

#endif