#include <stdio.h>
#include <string.h>

typedef struct _S_PALYER
{
    char m_szName[128];
    int m_nHp;
}_S_PALYER;

int main(void)
{
    struct _S_PALYER players[] = {
        {"john snow", 300},
        {"sansa stak", 200},
        {"seosai ranerster", 250}
    };

    for(int i = 0 ; i < 3 ; i++)
    {
        printf("name : %s, hp : %d \n", players[i].m_szName, players[i].m_nHp);
    }

    return 0;
}