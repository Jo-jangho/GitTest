#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>
#include <sys/select.h>
#include <termios.h>

#include "../engine2d/engine2d.h"
#include "map.h"

_S_MAP_OBJECT MapObject;

int main()
{
	int bLoop=1;

	MapObject.m_header.m_nSkima = 1;
	MapObject.m_pBuf = NULL;

	while(bLoop)
	{
		char szCmd[32];
		gets(szCmd);
		char *pTemp = strtok(szCmd," ");
		if(!strcmp(pTemp,"exit")) 
        {
			bLoop = 0;
			if( MapObject.m_pBuf ) 
            {
				free(MapObject.m_pBuf);
			}
		}
		else if( !strcmp(pTemp,"dump") )
        {
			map_dump(&MapObject);
		}
		else if(!strcmp(pTemp,"new")) 
        {
			int nWidth = atoi(strtok(NULL," "));
    		int nHeight = atoi(strtok(NULL," "));
			map_new(&MapObject, nWidth, nHeight);
		}
		else if(!strcmp(pTemp,"put")) 
        {		
			//put 1 2 1 (x y tile_index)
			int x = atoi(strtok(NULL, " "));
			int y = atoi(strtok(NULL, " "));
			int tile_index = atoi(strtok(NULL," "));

			map_put(&MapObject, x, y, tile_index);
		}
        else if(!strcmp(pTemp, "hline"))
        {
            //hline 1 1 
            int x = atoi(strtok(NULL, " "));
            int tile_index = atoi(strtok(NULL," "));

			map_hline(&MapObject, x, tile_index);
        }
        else if(!strcmp(pTemp, "vline"))
        {
            //hline 1 1 
            int y = atoi(strtok(NULL, " "));
            int tile_index = atoi(strtok(NULL," "));

            map_vline(&MapObject, y, tile_index);
        }
		else if(!strcmp(pTemp, "save"))
		{
			//save filename
			char* pFilename = strtok(NULL, " ");
			printf("save : %s \n", pFilename);

			map_save(&MapObject, pFilename);
		}
		else if(!strcmp(pTemp, "load"))
		{
			//load filename
			char* pFilename = strtok(NULL, " ");
			printf("load : %s \n", pFilename);

			map_load(&MapObject, pFilename);
		}
		else if(!strcmp(pTemp, "tridraw_1"))
		{
			for(int i = 0 ; i < MapObject.m_header.m_nHeight ; i++)
			{
				for(int j = 0 ; j <= i ; j++)
				{
					MapObject.m_pBuf[(i * MapObject.m_header.m_nWidth) + j] = 1;
				}
			}
		}
		else if(!strcmp(pTemp, "draw_cross"))
		{
			//draw_cross 1 2 1
			int x = atoi(strtok(NULL, " "));
			int y = atoi(strtok(NULL, " "));
			int tile_index = atoi(strtok(NULL, " "));
			int dx = 1;

			MapObject.m_pBuf[(y * MapObject.m_header.m_nWidth) + x] = 1;
			MapObject.m_pBuf[(y * MapObject.m_header.m_nWidth) + (x + dx)] = 1;
			MapObject.m_pBuf[(y * MapObject.m_header.m_nWidth) + (x - dx)] = 1;
			MapObject.m_pBuf[((y + dx) * MapObject.m_header.m_nWidth) + x] = 1;
			MapObject.m_pBuf[((y - dx) * MapObject.m_header.m_nWidth) + x] = 1;
		}
	}
		
	return 0;
}
