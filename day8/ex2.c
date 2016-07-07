#include <stdio.h>

typedef struct _S_WEPON
{
    int m_nAttack;
    int m_nEndure;  
}_S_WEPON;

typedef struct _S_PLAYER
{
    int m_nHp;
    int m_nMp;
    _S_WEPON m_sWeapon;
}_S_PLAYER;

int main(void)
{
    _S_PLAYER player1;

    player1.m_nHp = 100;
    player1.m_nMp = 50;
    player1.m_sWeapon.m_nAttack = 5;
    player1.m_sWeapon.m_nEndure = 10;

    printf("HP : %d\n", player1.m_nMp);
    printf("MP : %d\n", player1.m_nHp);
    printf("Attack : %d\n", player1.m_sWeapon.m_nAttack);
    printf("Endure : %d\n", player1.m_sWeapon.m_nEndure);

    return 0;
}