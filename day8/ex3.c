#include <stdio.h>

typedef struct _S_PLAYER
{
    int m_nHp;
    int m_nMp;
}_S_PLAYER;

int main(void)
{
    _S_PLAYER player1 = { 100,50 };

    printf("Hp : %d\nMp : %d\n", player1.m_nHp, player1.m_nMp);

    return 0;
}