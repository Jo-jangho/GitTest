#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _S_ITEM
{
    char m_szName[32];

    int m_nType;
    int m_nValue;

}_S_ITEM;

_S_ITEM item_list[] = {
    {"short sword", 0, 10},
    {"wood shild", 0, 5},
    {"dagger", 0, 6},
    {"sling", 0, 3},
    {"staff", 0, 7}
};

_S_ITEM *findItem(const char *szName)
{
    int item_list_length = sizeof(item_list) / sizeof(_S_ITEM);
    _S_ITEM *pitem;

    for(int i = 0 ; i < item_list_length ; i++)
    {
        pitem = &(item_list[i]);
        if(strcmp(szName, pitem->m_szName) == 0)
        {
            return pitem;
        }
    }
}

unsigned long getHashCode(const char *szStr)
{
    int nLength = strlen(szStr);

    int nHash = 5381;
    int c;

    for(int i = 0 ; i < nLength ; i++)
    {
        c = szStr[i];
        nHash = ((nHash<<5) + nHash) + c;
    }

    return nHash;
}

int main(void)
{
    // _S_ITEM *val = findItem("sling");

    // printf("%s %d", val->m_szName, val->m_nValue);

    //printf("%d, %d\r\n", getHashCode("staff"), getHashCode("step"));

    if(getHashCode("staff") == getHashCode("staeg"))
    {
        puts("같은 문장입니다.");
    }
    else
    {
        puts("다른 문장입니다.");
    }

    return 0;
}