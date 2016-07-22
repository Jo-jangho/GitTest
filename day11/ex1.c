#include "engine2d.h"
#include "map.h"

int main(void)
{
    _S_MAP_OBJECT test_map;
    _S_MAP_OBJECT test_map2;
    map_init(&test_map);
    map_init(&test_map2);

    map_new(&test_map, 8, 8);
    map_dump(&test_map);

    map_new(&test_map2, 4, 4);
    map_dump(&test_map2);

    return 0;
}