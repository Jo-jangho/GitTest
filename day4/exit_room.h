#ifndef __EXIT_ROOM_H__
#define __EXIT_ROOM_H__

/*
0 : 길
1 : 벽
2 : 열린문
3 : 플레이어
4 : 잠긴문
5 : 열쇠
*/

/* var */
int world_mapA[64]= {
    1, 4, 1, 1, 1, 1, 1, 1,
    1, 0, 1, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 1, 1, 0, 1,
    1, 1, 1, 1, 1, 1, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 1,
    1, 1, 1, 0, 1, 1, 1, 1,
    1, 0, 0, 0, 0, 0, 5, 1,
    1, 0, 1, 1, 1, 1, 1, 1
};

int world_mapB[64] = {
    1, 4, 1, 1, 1, 1, 1, 1,
    1, 0, 1, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 1, 1, 0, 1,
    1, 1, 1, 1, 1, 1, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 1,
    1, 1, 1, 0, 1, 1, 1, 1,
    1, 0, 0, 0, 0, 0, 5, 1,
    1, 0, 1, 1, 1, 1, 1, 1
};

int player_xPos;
int player_yPos;
int bLoop = 1;
static int collision = 1;

// 0. 준비  1. 플레이  2. 레벨클리어  3. 종료
int nFSM = 0;               


/* 더블 버퍼 */
void setAllMap(int* world_mapA, int* world_mapB)
{
    for(int i = 0 ; i < 64 ; i++)
    {
        world_mapA[i] = world_mapB[i];
    }
}

/* 충돌 처리 */
int colliedBox(int* world_mapA, int player_xPos, int player_yPos)
{
    if( 0 > player_xPos)
    {
        printf("벽으로 막혀있습니다.\n");
        return 0;
    }
    else if(player_xPos > 7)
    {
        printf("벽으로 막혀있습니다.\n");
        return 0;
    }
    else if( 0 > player_yPos)
    {
        printf("벽으로 막혀있습니다.\n");
        return 0;
    }
    else if(player_yPos > 7)
    {
        printf("벽으로 막혀있습니다.\n");
        return 0;
    }
    else if(world_mapA[player_xPos + (player_yPos + 8)] == 1)
    {
        printf("벽으로 막혀있습니다.\n");
        return 0;
    }
    else if(world_mapA[player_xPos + (player_yPos + 8)] == 2)
    {
        printf("도착~!");
        return 0;
    }
    else if(world_mapA[player_xPos + (player_yPos + 8)] == 4)
    {
        printf("문이 잠겨있습니다.");
        return 0;
    }
    else if(world_mapA[player_xPos + (player_yPos + 8)] == 5)
    {
        printf("열쇠 획득!");
        return 0;
    }

    return 1;
}

/* 플레이어 이동 */
void move_player(char cmd)
{
    switch(cmd)
    {
    case 'w':
        setAllMap(world_mapA, world_mapB);
        player_yPos -= 1;
        collision = colliedBox(world_mapA, player_xPos, player_yPos);
        if(collision == 0)
        {
            player_yPos += 1;
        }
        break;
    case 's':
        setAllMap(world_mapA, world_mapB);
        player_yPos += 1;       
        collision = colliedBox(world_mapA, player_xPos, player_yPos);
        if(collision == 0)
        {
            player_yPos -= 1;
        }
        break;
    case 'a':
        setAllMap(world_mapA, world_mapB);
        player_xPos -= 1;
        collision = colliedBox(world_mapA, player_xPos, player_yPos);
        if(collision == 0)
        {
            player_xPos += 1;
        }
        break;
    case 'd':
        setAllMap(world_mapA, world_mapB);
        player_xPos += 1;
        collision = colliedBox(world_mapA, player_xPos, player_yPos);
        if(collision == 0)
        {
            player_xPos -= 1;
        }
        break;
    }
}

#endif