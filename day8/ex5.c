#include <stdio.h>
#include <stdlib.h>

typedef struct _S_PLAYER
{
    int m_nHp;
    char m_szName[128];
}_S_PLAYER;

int main(void)
{
    _S_PLAYER *pPlayer;

    pPlayer = (_S_PLAYER *)malloc(sizeof(_S_PLAYER));

    pPlayer->m_nHp = 100;
    strcpy(pPlayer->m_szName, "aria stak");

    free(pPlayer);

    return 0;
}