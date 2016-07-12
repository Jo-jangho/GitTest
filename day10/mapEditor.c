#include "engine2d.h"

typedef struct
{
	int m_nSkima;
	int m_nWidth;
	int m_nHeight;
}_S_MAP_HEADER;


typedef struct
{
	_S_MAP_HEADER m_header;
	char *m_pBuf;
}_S_MAP_OBJECT;

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
			putTile(
			0,MapObject.m_header.m_nHeight,
			0,MapObject.m_header.m_nWidth,
			MapObject.m_header.m_nWidth,
			MapObject.m_pBuf
			);
		}
		else if(!strcmp(pTemp,"new")) 
        {
			//new 8 4
			if(MapObject.m_pBuf != NULL) 
            {
                free(MapObject.m_pBuf); 
            }
			MapObject.m_header.m_nWidth = atoi(strtok(NULL," "));
			MapObject.m_header.m_nHeight = atoi(strtok(NULL," "));
			MapObject.m_pBuf = malloc( MapObject.m_header.m_nHeight * MapObject.m_header.m_nWidth );

			for(int i = 0 ; i <	MapObject.m_header.m_nHeight * MapObject.m_header.m_nWidth ; i++) 
            {
				MapObject.m_pBuf[i] = 0;
			}
		}
		else if(!strcmp(pTemp,"put")) 
        {
			//put 1 2 1 (x y tile_index)
			int x, y, tile_index;
			x = atoi(strtok(NULL, " "));
			y = atoi(strtok(NULL, " "));
			tile_index = atoi(strtok(NULL," "));

			MapObject.m_pBuf[ (y * MapObject.m_header.m_nWidth) + x ] = tile_index;
		
		}
        else if(!strcmp(pTemp, "hline"))
        {
            //hline 1 1 
            int x, y, tile_index;
            x = atoi(strtok(NULL, " "));
            tile_index = atoi(strtok(NULL," "));

            for(int i = 0 ; i < MapObject.m_header.m_nHeight ; i++)
            {
                MapObject.m_pBuf[ (i * MapObject.m_header.m_nWidth) + x ] = tile_index;
            }
        }
        else if(!strcmp(pTemp, "vline"))
        {
            //hline 1 1 
            int x, y, tile_index;
            y = atoi(strtok(NULL, " "));
            tile_index = atoi(strtok(NULL," "));

            for(int i = 0 ; i < MapObject.m_header.m_nWidth ; i++)
            {
                MapObject.m_pBuf[ (y * MapObject.m_header.m_nWidth) + i ] = tile_index;
            }
        }
		else if(!strcmp(pTemp, "save"))
		{
			//save filename
			char* szFileName = strtok(NULL, " ");
			printf("save : %s \n", szFileName);

			FILE* pFile = fopen(szFileName, "w");

			/**/
			fprintf(pFile, "%d", MapObject.m_header.m_nWidth);
			fputs(" ", pFile);
			fprintf(pFile, "%d", MapObject.m_header.m_nHeight);
			fputs(" ", pFile);
			for(int i = 0 ; i <	MapObject.m_header.m_nHeight * MapObject.m_header.m_nWidth ; i++) 
            {
				fprintf(pFile, "%d ", MapObject.m_pBuf[i]);
			}
			
			/**/
			fclose(pFile);
		}
		else if(!strcmp(pTemp, "load"))
		{
			//load filename
			char* szFileName = strtok(NULL, " ");
			printf("load : %s \n", szFileName);

			FILE* pFile = fopen(szFileName, "r");

			/**/
			fscanf(pFile, "%d", &MapObject.m_header.m_nWidth);
			fscanf(pFile, "%d", &MapObject.m_header.m_nHeight);
			
			MapObject.m_pBuf = malloc( MapObject.m_header.m_nHeight * MapObject.m_header.m_nWidth );
			for(int i = 0 ; i <	MapObject.m_header.m_nHeight * MapObject.m_header.m_nWidth ; i++) 
            {
				fscanf(pFile, "%d", &MapObject.m_pBuf[i]);
			}
			
			/**/
			fclose(pFile);
		}
	}
		
	return 0;
}
