#include "engine2d.h"
#include "exit_room.h"

int main(void)
{
    char cmd;

    /**/
    while(bLoop)
    {
        switch(nFSM)
        {
        case 0:
            printf("명령을 선택하세요\np(시작), q(종료))\n");
            break;
        case 1:
            printf("명령을 선택하세요\n (w(위), a(좌), s(아래), d(우), q(종료))\n");
            break;
        case 2:
            break;
        }
        
        scanf("%c", &cmd);
        system("clear");

        if(nFSM == 0)
        {
            switch(cmd)
            {
            case 'p':
                nFSM = 1;
                player_xPos = 1;
                player_yPos = 7;
                printf("게임을 시작합니다.");
                break;
            case 'q':
                bLoop = 0;
                nFSM = 2;
                break;
            }
        }
        else if(nFSM == 1)
        {
            world_mapA[player_xPos + (player_yPos * 8)] = 3;
            map_drawAll(world_mapA);

            move_player(cmd);
            
            switch(cmd)
            {
                case 'q':
                    bLoop = 0;
                    nFSM = 2;
                    break;
            }
            
            if(collision == -1)
            {
                nFSM = 0;
            }
        }
        else if(nFSM == 2)
        {
            nFSM = 0;
        }   
    }
    return 0;
}