#ifndef __EXIT_ROOM_H__
#define __EXIT_ROOM_H__

/*
 *
 1 : 벽 #
 2:  열린문 M
 3 : 게임머 A
 4: 잠긴문 m
 5: 키 K
 */

int world_map[] = {
	1,4,1,1,1,1,1,1,
	1,0,0,1,0,0,0,1,
	1,0,0,0,0,1,0,1,
	1,1,1,1,1,1,0,1,
	1,0,0,0,0,0,0,1,
	1,1,1,0,1,1,1,1,
	1,0,0,0,0,0,5,1,
	1,0,1,1,1,1,1,1
};

int buffer_map[64];

int game_version = 1;
char *game_name = "방탈출 게임"; 


//0 준비
//1 게임 플레이
//2 레벨클리어
//3 게임오버 
int nFSM = 0;

int player_xpos;
int player_ypos;
int player_inven; //0없음, 1:키보유 

void colliedBox(int old_xpos, int old_ypos)
{
    switch(buffer_map[ player_xpos + player_ypos*8 ] ) 
    {
    case 0: //공간
        break;
    case 1: //벽
        player_ypos = old_ypos;
        player_xpos = old_xpos;
        break;
    case 2: //문 
        if(player_inven == 1) 
        {
            printf("미션클리어 \r\n");
            nFSM = 2;
        }
        else 
        {
            player_ypos = old_ypos;
            player_xpos = old_xpos;
        }
        break;
    case 4:
        player_ypos = old_ypos;
        player_xpos = old_xpos;
        break;
    case 5:
        printf("키를 얻었습니다. \r\n");
        player_inven = 1;
        break;

	}
}

void move_player(char cmd)
{
	int old_xpos = player_xpos;
	int old_ypos = player_ypos;

	switch(cmd)
	{
    case 'w':
        player_ypos -=1;
        break;
    case 'a':
        player_xpos -=1;
        break;
    case 'd':
        player_xpos += 1;
        break;
    case 's':
        player_ypos += 1;
        break;
	}

	colliedBox(old_xpos, old_ypos);

	buffer_map[ player_xpos + player_ypos*8 ] = 3;
    map_drawAll(buffer_map);

}

#endif

