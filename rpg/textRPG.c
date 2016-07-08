#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char* m_szName;
    void* node[8];
}S_AREA;

int main(void)
{
    S_AREA town = {
        "town",
        NULL, NULL, NULL, 
        NULL,       NULL, 
        NULL, NULL, NULL
    };

    S_AREA dungeon_1 = {
        "dungeon - 1",
        NULL, NULL, NULL, 
        NULL,       NULL, 
        NULL, NULL, NULL
    };

    town.node[0] = &dungeon_1;
    dungeon_1.node[0] = &town;

    S_AREA* pCurrentArea = &town;

    int bLoop = 1;
    while(bLoop)
    {
        char szCmd[32];
        gets(szCmd);
        char* pTemp = strtok(szCmd, " ");

        if(!strcmp(pTemp, "look"))
        {
            printf("당신은 %s에 서 있습니다.\n", pCurrentArea->m_szName);
        }
        else if(!strcmp(pTemp, "exit"))
        {
            bLoop = 0;
        }
        else if(!strcmp(pTemp, "move"))
        {
            char* pszArea = strtok(NULL, " ");
            printf("당신은 %s으로 이동합니다.\n", pszArea);

            for(int i = 0 ; i < 8 ; i++)
            {
                S_AREA* pNode = pCurrentArea->node[i];
                
                if(pNode == NULL) break;

                if(!strcmp(pNode->m_szName, pszArea))
                {
                    puts("이동 성공");
                    pCurrentArea = pNode;
                }
            }
            
        }
    }

    return 0;
}