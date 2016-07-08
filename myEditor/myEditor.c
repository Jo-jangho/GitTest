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
void push()
{
    /**/
    pTemp = strtok(NULL, " ");
    pstr = (char *)malloc(strlen(pTemp) + 1);
    strcpy(pstr, pTemp);

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

void insert()
{
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
    //rm 1
    int nIdx = atoi(strtok(NULL, " "));
    pTemp = strtok(NULL, " ");

    /**/
    S_STRLINE* pLine = pHeader;
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

void change()
{
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

void pop()
{
    S_STRLINE* pNext = (S_STRLINE *)pHeader;
    S_STRLINE* pDel = (S_STRLINE *)pTail;
    while(pNext->m_pNext != pDel)
    {
        pNext = pNext->m_pNext;
    }
    pTail = pNext;
    pTail->m_pNext = NULL;

    free(pDel->m_szStr);
    free(pDel);
}

void delete()
{
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
