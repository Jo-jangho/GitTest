#include <stdio.h>

void draw_tri1()
{
    for(int i = 0 ; i < 10 ; i++)
    {
        for(int j = 0 ; j < i ; j++)
        {
            putchar('*');
        }
        puts("");
    }
}

void draw_tri2()
{
    for(int i = 0 ; i < 10 ; i++)
    {
        for(int j = 10 ; j > i ; j--)
        {
            putchar(' ');
        }
        for(int j = 0 ; j <= i ; j++)
        {
            putchar('*');
        }
        puts("");
    }
}

void invertTri()
{
    for(int i = 0 ; i < 10 ; i++)
    {
        for(int j = 10 ; j > i ; j--)
        {
            putchar('*');
        }
        puts("");
    }
}

void pyramid()
{
    for(int i = 0 ; i < 10 ; i++)
    {
        for(int j = 10 ; j > i ; j--)
        {
            putchar(' ');
        }
        for(int j = 0 ; j <= i * 2 ; j++)
        {
            putchar('*');
        }
        puts("");
    }
}

int main(void)
{
    draw_tri1();

    invertTri();

    draw_tri2();

    pyramid();

    return 0;
}