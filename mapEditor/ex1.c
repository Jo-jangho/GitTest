#include "engine2d.h"
#include "map.h"

int main(void)
{
    _S_MAP_OBJECT screenBuffer;
    _S_MAP_OBJECT carObj;
    map_init(&screenBuffer);
    map_init(&carObj);

    map_new(&screenBuffer, 16, 16);
    map_load(&carObj, "car.dat");

    _S_MAP_OBJECT *pObj = &carObj;
    for( int i = 0 ; i < pObj->m_header.m_nHeight ; i++)
    {
        for(int j = 0 ; j < pObj->m_header.m_nWidth ; j++)
        {
            map_put(&screenBuffer, i, j, 
            pObj->m_pBuf[(i * pObj->m_header.m_nWidth) + j]);
        }
    }

    map_dump(&screenBuffer);

    return 0;
}