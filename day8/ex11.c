#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char m_szName[32];
    int m_nHp;
}S_PLAYER;

int main(void)
{
    S_PLAYER player = {
        "안철수",
        100
    };

    FILE* pf = fopen("test.dat", "wb");

    fwrite(&player, sizeof(S_PLAYER), 1, pf);

    fclose(pf);

    return 0;
}