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

_S_ITEM *findItem(const char *szName)
{
    int item_list_length = sizeof(item_list) / sizeof(_S_ITEM);
    unsigned long hcode1 = getHashCode(szName);
    _S_ITEM *pitem;

    for(int i = 0 ; i < item_list_length ; i++)
    {
        pitem = &(item_list[i]);
        if(getHashCode(pitem->m_szName) == hcode1)
        {
            return pitem;
        }
    }
}

int main(void)
{
    _S_ITEM *val = findItem("sling");

    printf("%s %d", val->m_szName, val->m_nValue);

    return 0;
}