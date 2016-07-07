#include <stdio.h>

typedef struct
{
    char m_szName[128];
    int m_nHp;
}_S_PLAYER;

//typedef struct _S_PLAYER _S_Player

int main(void)
{
    _S_Player player = {
        "player1", 100
    };

    return 0;
}