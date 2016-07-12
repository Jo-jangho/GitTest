#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *pMapBuf;

void putTile(int sy, int ey, int sx, int ex, int width, char *ptrBuf)
{
    for(int i = sy ; i < ey ; i++)
    {
        for(int j = sx ; j < ex ; j++)
        {
            switch(ptrBuf[ (i * width) + j])
            {
                case 0:
                    printf(" .");
                    break;
                case 1:
                    printf(" @");
                    break;
                case 2:
                    printf(" A");
                    break;
            }
        }
        printf("\r\n");
    }
}

void readMap()
{
    int width,height;
	FILE *pf;
	pf = fopen("./map.txt","r");
	
	char buf[256];

	fgets(buf, 256, pf);

	char *pTemp = strtok(buf, ",");
	width = atoi(pTemp);
	pTemp = strtok(NULL, ",");
	height = atoi(pTemp);

	pMapBuf = (char *)malloc(width * height);
	
	int ix,iy;
	for(iy = 0 ; iy < height ; iy++) {
		fgets(buf, 256, pf);
		pTemp = strtok(buf, ",");
		pMapBuf[iy * width + 0] = atoi(pTemp);
		for(ix=1 ; ix < width ; ix++) {
			pTemp = strtok(NULL,",");
			pMapBuf[iy * width + ix] = atoi(pTemp);
		}
	}
	
	putTile(0, height, 0, width, width, pMapBuf);

	free(pMapBuf);
	fclose(pf);
}

int main(void)
{
    readMap();

    return 0;
}