#include "engine2d.h"
#include "map.h"

int main(void)
{
    _S_MAP_OBJECT screenBuf;
    map_init(&screenBuf);
    map_new(&screenBuf, 16, 16);

    map_put(&screenBuf, 7, 5, 4);
    map_put(&screenBuf, 6, 5, 4);
    map_put(&screenBuf, 5, 5, 4);
    map_put(&screenBuf, 4, 5, 4);
    map_put(&screenBuf, 3, 5, 4);

    _S_MAP_OBJECT humanObj;
    map_init(&humanObj);
    map_load(&humanObj, "human.dat");

    map_drawTile(&humanObj, 5, 5, &screenBuf);

    map_dump(&screenBuf);

    return 0;
}
