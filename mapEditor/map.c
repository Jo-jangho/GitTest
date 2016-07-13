#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>
#include <sys/select.h>
#include <termios.h>

#include "map.h"

/**/
char tilePalette[] = {'.', '#', '@', '/', 92, 
                        '+', '=', '^', '>', '<', 
                        '|', '-', '*'};

void map_init(_S_MAP_OBJECT *pObj)
{
    pObj->m_pBuf = NULL;
}

void map_dump(_S_MAP_OBJECT *pObj)
{
    for(int iy = 0 ; iy < pObj->m_header.m_nHeight ; iy++) 
    {
		for(int ix = 0; ix < pObj->m_header.m_nWidth ; ix++) 
        {
			putchar(tilePalette[ pObj->m_pBuf[ iy * pObj->m_header.m_nWidth + ix]]);
		}
		printf("\r\n");
	}
}

void map_new(_S_MAP_OBJECT *pObj, int nWidth, int nHeight)
{
    //new 8 4
    if(pObj->m_pBuf != NULL) 
    {
        free(pObj->m_pBuf); 
    }
    pObj->m_header.m_nWidth = nWidth;
    pObj->m_header.m_nHeight = nHeight;
    pObj->m_pBuf = malloc( nHeight * nWidth );

    for(int i = 0 ; i <	nHeight * nWidth ; i++) 
    {
        pObj->m_pBuf[i] = 0;
    }
}

void map_put(_S_MAP_OBJECT *pObj, int x, int y, int tile_index)
{

    pObj->m_pBuf[ (y * pObj->m_header.m_nWidth) + x ] = tile_index;
}

void map_hline(_S_MAP_OBJECT *pObj, int x, int tile_index)
{
    for(int i = 0 ; i < pObj->m_header.m_nHeight ; i++)
    {
        pObj->m_pBuf[ (i * pObj->m_header.m_nWidth) + x ] = tile_index;
    }
}

void map_vline(_S_MAP_OBJECT *pObj, int y, int tile_index)
{
    for(int i = 0 ; i < pObj->m_header.m_nWidth ; i++)
    {
        pObj->m_pBuf[ (y * pObj->m_header.m_nWidth) + i ] = tile_index;
    }
}

void map_drawTile(_S_MAP_OBJECT *pObj, int posX, int posY, _S_MAP_OBJECT *pTarget)
{
    for( int i = 0 ; i < pObj->m_header.m_nHeight ; i++)
    {
        for(int j = 0 ; j < pObj->m_header.m_nWidth ; j++)
        {
            map_put(pTarget, j + posX, i + posY, 
            pObj->m_pBuf[(i * pObj->m_header.m_nWidth) + j]);
        }
    }
}

void map_drawTile_trn(_S_MAP_OBJECT *pObj, int posX, int posY, _S_MAP_OBJECT *pTarget)
{
    for( int i = 0 ; i < pObj->m_header.m_nHeight ; i++)
    {
        for(int j = 0 ; j < pObj->m_header.m_nWidth ; j++)
        {
            if(pObj->m_pBuf[(i * pObj->m_header.m_nWidth) + j] != 0)
            {
                map_put(pTarget, j + posX, i + posY, 
                pObj->m_pBuf[(i * pObj->m_header.m_nWidth) + j]);
            }
        }
    }
}

void map_drawTkle_mirrorV(_S_MAP_OBJECT *pObj, int posX, int posY, _S_MAP_OBJECT *pTarget)
{
    for( int i = 0 ; i < pObj->m_header.m_nHeight ; i++)
    {
        for(int j = 0 ; j < pObj->m_header.m_nWidth ; j++)
        {
            if(pObj->m_pBuf[(i * pObj->m_header.m_nWidth) + j] != 0)
            {
                map_put(pTarget, -j + posX, i + posY, 
                pObj->m_pBuf[(i * pObj->m_header.m_nWidth) + j]);
            }
        }
    }
}

void map_drawTkle_mirrorH(_S_MAP_OBJECT *pObj, int posX, int posY, _S_MAP_OBJECT *pTarget)
{
    for( int i = 0 ; i < pObj->m_header.m_nHeight ; i++)
    {
        for(int j = 0 ; j < pObj->m_header.m_nWidth ; j++)
        {
            if(pObj->m_pBuf[(i * pObj->m_header.m_nWidth) + j] != 0)
            {
                map_put(pTarget, j + posX, -i + posY, 
                pObj->m_pBuf[(i * pObj->m_header.m_nWidth) + j]);
            }
        }
    }
}

// 0 : 실패
// 1 : 성공
int map_save(_S_MAP_OBJECT *pObj, char *filename)
{
    FILE* pFile = fopen(filename, "wb");

    /**/
    fprintf(pFile, "%d", pObj->m_header.m_nWidth);
    fputs(" ", pFile);
    fprintf(pFile, "%d", pObj->m_header.m_nHeight);
    fputs(" ", pFile);
    for(int i = 0 ; i <	pObj->m_header.m_nHeight * pObj->m_header.m_nWidth ; i++) 
    {
        fprintf(pFile, "%d ", pObj->m_pBuf[i]);
    }

    /*fwrite(&MapObject.m_header, sizeof(MapObject.m_header), 1, pFile);
    int nSize = MapObject.m_header.m_nHeight * MapObject.m_header.m_nWidth;
    fwrite(MapObject.m_pBuf, nSize, 1, pFile);*/
    /**/
    fclose(pFile);

    return 1;
}

// 0 : 실패
// 1 : 성공
int map_load(_S_MAP_OBJECT *pObj, char *filename)
{
    FILE* pFile = fopen(filename, "rb");

    /**/
    fscanf(pFile, "%d", &pObj->m_header.m_nWidth);
    fscanf(pFile, "%d", &pObj->m_header.m_nHeight);
    
    pObj->m_pBuf = malloc( pObj->m_header.m_nHeight * pObj->m_header.m_nWidth );
    for(int i = 0 ; i <	pObj->m_header.m_nHeight * pObj->m_header.m_nWidth ; i++) 
    {
        fscanf(pFile, "%d", &pObj->m_pBuf[i]);
    }

    /*fread(&MapObject.m_header, sizeof(_S_MAP_OBJECT), 1, pFile);
    if(MapObject.m_pBuf)
    {
        free(MapObject.m_pBuf);
    }
    MapObject.m_pBuf = malloc( MapObject.m_header.m_nHeight * MapObject.m_header.m_nWidth );
    int nSize = MapObject.m_header.m_nHeight * MapObject.m_header.m_nWidth;
    MapObject.m_pBuf = malloc(nSize);
    fread(MapObject.m_pBuf, nSize, 1, pFile);*/
    /**/
    fclose(pFile);

    return 1;
}