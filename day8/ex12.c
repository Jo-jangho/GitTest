#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char m_szName[32];
    int m_nHp;
}S_PLAYER;

int main(void)
{
    S_PLAYER player;

    FILE* pf = fopen("test.dat", "rb");

    fread(&player, sizeof(S_PLAYER), 1, pf);

    fclose(pf);

    puts(player.m_szName);
    //puts(player.m_nHp);

    return 0;
}