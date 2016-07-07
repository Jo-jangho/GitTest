#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _S_HUMAN
{
    int m_nHp;
    int m_nMp;
    int m_nLevel;
    double m_dbAp;
    char m_szName[128];
}_S_HUMAN;

int main(void)
{
    _S_HUMAN human;

    human.m_nHp = 100;
    human.m_nMp = 50;
    human.m_nLevel = 1;
    human.m_dbAp = 3.5;
    strcpy(human.m_szName, "athuer");

    printf("hp : %d\n", human.m_nHp);
    printf("mp : %d\n", human.m_nMp);
    printf("level : %d\n", human.m_nLevel);
    printf("ap : %.1f\n", human.m_dbAp);
    printf("name : %s\n", human.m_szName);

    return 0;
}