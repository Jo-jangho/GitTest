#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myEditor.h"

typedef struct
{
    char* m_szToken;
    void (*m_fp)();
}S_PROC_OBJECT;

/**/
S_STRLINE* pHeader = NULL;
S_STRLINE* pTail = NULL;

char* pTemp;
char* pstr;

/**/
void _me_push();
void me_push();
void me_insert();
void me_remove();
void me_change();
void me_pop();
void me_delete();
void me_dump();
void me_readfile();
void me_writefile();

/**/
S_PROC_OBJECT proc_objects[] = {
    {"push", me_push},
    {"insert", me_insert},
    {"rm", me_remove},
    {"change", me_change},
    {"pop", me_pop},
    {"delete", me_delete},
    {"dump", me_dump},
    {"read", me_readfile},
    {"write", me_writefile}
};

void apply(char* szToken)
{
    for(int i = 0 ; i < sizeof(proc_objects) / sizeof(S_PROC_OBJECT) ; i++)
    {
        if(strcmp(proc_objects[i].m_szToken, szToken) == 0)
        {
            proc_objects[i].m_fp();
            break;
        }
    }
}

/**/
void me_readfile()
{
    //read file
    char* szFileName = strtok(NULL, " ");
    printf("read : %s \n", szFileName);

    FILE* pFile = fopen(szFileName, "r");

    char szBuf[512];
    char* pTemp;

    while(1)
    {
        if(fgets(szBuf, 512, pFile) == NULL) break;

        _me_push(szBuf);
    }
    
    fclose(pFile);
}

void me_writefile()
{
    //write file
    char* szFileName = strtok(NULL, " ");
    printf("write : %s \n", szFileName);

    FILE* pFile = fopen(szFileName, "w");

    /**/
    S_STRLINE* pLine = (S_STRLINE *)pHeader;
    while(pLine != NULL)
    {
        fputs(pLine->m_szStr, pFile);
        fputs("\n", pFile);
        pLine = pLine->m_pNext;
    }

    /**/
    fclose(pFile);
}

/**/
void _me_push(char* szText)
{
    /**/
    pstr = (char *)malloc(strlen(szText) + 1);
    strcpy(pstr, szText);

    /**/
    S_STRLINE* pLine = (S_STRLINE *)malloc(sizeof(S_STRLINE));
    pLine->m_szStr = pstr;
    pLine->m_pNext = NULL;

    /**/
    if(pHeader == NULL)
    {
        pHeader = pLine;
        pTail = pLine;
    }
    else
    {
        S_STRLINE* pNext = (S_STRLINE *)pHeader;
        while(pNext != NULL)
        {
            if(pNext->m_pNext != NULL)
            {
                pNext = pNext->m_pNext;
            }
            else
            {
                pNext->m_pNext = pLine;
                pTail = pLine;
                pNext = NULL;
            }
        }
    }
}

void me_push()
{
    /**/
    pTemp = strtok(NULL, " ");
    _me_push(pTemp);
}

void me_insert()
{
    if(pTail == NULL)
    {
        puts("push를 먼저 해주세요");
        return;
    }
    //insert 2 hello
    int nIdx = atoi(strtok(NULL, " "));
    pTemp = strtok(NULL, " ");

    pstr = (char *)malloc(strlen(pTemp) + 1);
    strcpy(pstr, pTemp);

    /**/
    S_STRLINE* pLine = (S_STRLINE *)malloc(sizeof(S_STRLINE));
    pLine->m_szStr = pstr;

    /**/
    S_STRLINE* pNext = pHeader;
    int i = 1;
    while( i < nIdx )
    {
        pNext = pNext->m_pNext;
        i++;
    }

    /**/
    pLine->m_pNext = pNext->m_pNext;
    pNext->m_pNext = pLine;
}

void me_remove()
{
    if(pTail == NULL)
    {
        puts("push를 먼저 해주세요");
        return;
    }
    //rm 1
    int nIdx = atoi(strtok(NULL, " "));
    pTemp = strtok(NULL, " ");

    /**/
    S_STRLINE* pLine = pHeader;
    S_STRLINE* pDel = pHeader;
    if(pHeader == pTail)
    {
        free(pDel->m_szStr);
        free(pDel);
        pHeader = NULL;
        pTail = NULL;
    }
    else
    {
        int i = 1;
        while( i < nIdx )
        {
            pLine = pLine->m_pNext;
            i++;
        }

        /**/
        S_STRLINE* pDel = pLine->m_pNext;
        pLine->m_pNext = pDel->m_pNext;
        free(pDel);
    }
}

void me_change()
{
    if(pTail == NULL)
    {
        puts("push를 먼저 해주세요");
        return;
    }
    //change 2 hello
    int nIdx = atoi(strtok(NULL, " "));

    pTemp = strtok(NULL, " ");

    pstr = (char *)malloc(strlen(pTemp) + 1);
    strcpy(pstr, pTemp);

    /**/
    S_STRLINE* pLine = pHeader;
    int i = 0;
    while( i < nIdx )
    {
        pLine = pLine->m_pNext;
        i++;
    }

    /**/
    free(pLine->m_szStr);

    /**/
    pLine->m_szStr = pstr;
}

void me_pop()
{
    if(pTail == NULL)
    {
        puts("push를 먼저 해주세요");
        return;
    }
    S_STRLINE* pNext = (S_STRLINE *)pHeader;
    S_STRLINE* pDel = (S_STRLINE *)pTail;

    if(pHeader == pTail)
    {
        free(pDel->m_szStr);
        free(pDel);
        pHeader = NULL;
        pTail = NULL;
    }
    else
    {
        while(pNext->m_pNext != pDel)
        {
            pNext = pNext->m_pNext;
        }
        pDel = pNext;
        pDel->m_pNext = NULL;
        pTail = pNext;

        free(pDel->m_szStr);
        free(pDel);
    }
}

void me_delete()
{
    if(pTail == NULL)
    {
        puts("push를 먼저 해주세요");
        return;
    }
    S_STRLINE* pDel = pHeader;
    pHeader = pHeader->m_pNext;

    free(pDel->m_szStr);
    free(pDel);
}

void me_dump()
{
    S_STRLINE* pLine = (S_STRLINE *)pHeader;
    puts("====================================");
    while(pLine != NULL)
    {
        printf("%s\n", pLine->m_szStr);
        pLine = pLine->m_pNext;
    }
    puts("====================================");
}