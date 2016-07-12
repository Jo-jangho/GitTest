#include "engine2d.h"

struct timespec work_timer;
double acc_tick, last_tick;
int nCount = 23;

int main(void)
{
    readMap();
    set_conio_terminal_mode();
    acc_tick = 0;
    last_tick = 0;

    int bLoop = 1;
    while(bLoop)
    {
        if(kbhit() != 0)
        {
            char ch = getch();
            if(ch == 'q')
            {
                free(pMapBuf);
                bLoop = 0;
            }
        }
        clock_gettime(CLOCK_MONOTONIC, &work_timer);
        double cur_tick = work_timer.tv_sec + (double)(work_timer.tv_nsec * 1e-9);
        double delta_tick = cur_tick - last_tick;
        last_tick = cur_tick;

        acc_tick += delta_tick;
        if(acc_tick > 1.0)
        {
            acc_tick = 0;
            system("clear");
            putTile(nCount, nCount + 10, 0, 8, 8, pMapBuf);
            
            nCount--;
            if(nCount < 0)
            {
                nCount = 23;
            }
        }
    }

    return 0;
}