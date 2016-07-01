#include "engine2d.h"
#include "exit_room.h"

int main(void)
{
	char cmd;
	int bLoop = 1;

	while(bLoop) 
    {
		switch(nFSM) 
        {
        case 0:
            printf("%s의 세계에 오신걸 환영합니다. V. %d \n ", game_name, game_version );
            printf("select => [p,q] \n");
            break;
        case 1:
            printf("명령을 선택하세요,\nw(up), a(left), d(right), s(down), m(show map), q(exit)\n");
            break;
        case 2:
            break;

		}

		//버퍼초기화
		for(int i = 0 ; i < 64 ; i++) 
        {
			buffer_map[i] = world_map[i];

		}

		scanf("%c",&cmd);
        system("clear");

		if(nFSM == 0) 
        {
			switch(cmd) 
            {
            case 'p': //게임스타트
                nFSM = 1;
                player_ypos = 7;
                player_xpos = 1;
                player_inven = 0;
                printf("게임을 시작합니다.");
                break;
            case 'q':
                bLoop = 0;
                printf("bye \r\n");
                break;

			}
		}
		else if(nFSM == 1 ) //게임플레이 중일때..
        { 
			move_player(cmd);
			switch(cmd) 
            {
            case 'q':
                bLoop = 0;
                printf("bye bye~\r\n"); 
                break;

			}
		}
		else if(nFSM == 2) 
        {
			nFSM = 0;

		}
	}
	return 0;
}
