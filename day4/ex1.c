#include "engine2d.h"

int main(void)
{
    /**/
    int world_map[] = {
        1, 2, 1, 1, 1, 1, 1, 1,
        1, 0, 1, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 1, 1, 0, 1,
        1, 1, 1, 1, 1, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 1,
        1, 1, 1, 0, 1, 1, 1, 1,
        1, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 1, 1, 1, 1, 1, 1
    };

    char cmd;
    int bLoop = 1;
    int player_xPos = 1;
    int player_yPos = 7;

    /**/
    while(bLoop)
    {
        //system("clear");

        printf("명령을 선택하세요\n(w(위), a(좌), s(아래), d(우), m(맵), q(종료))");
        scanf("%c", &cmd);

        /**/
        world_map[player_xPos + (player_yPos * 8)] = 3;

        switch(cmd)
        {
            case 'w':
                player_yPos -= 1;
                break;
            case 's':
                player_yPos += 1;
                break;
            case 'a':
                player_xPos -= 1;
                break;
            case 'd':
                player_xPos += 1;
                break;
            case 'm':
                map_drawAll(world_map);
                break;
            case 'q':
                bLoop = 0;
                break;
        }
    }

    return 0;
}