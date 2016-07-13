#include "engine2d.h"
#include "map.h"

int main(void)
{
    _S_MAP_OBJECT car;
    
    map_init(&car);

    map_load(&car, "car.dat");

    map_dump(&car);

    return 0;
}