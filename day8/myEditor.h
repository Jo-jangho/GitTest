#ifnedf __MY_EDITOR_H__
#define __MY_EDITOR_H__

/*
push str
pop
del
rm index
ins index str
set index str
*/

typedef struct
{
    char* szStr;
    void* pNext;
}S_STRLINE;



#endif