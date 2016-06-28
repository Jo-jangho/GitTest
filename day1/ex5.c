#include <stdio.h>
#include <stdlib.h>

/* 글자 속성 */
#define RESET 0
#define BRIGHT 1
#define DIM 2
#define UNDERSCORE 4
#define BLINK 5
#define REVERSE 7
#define HIDDNE 8

/* 글자색 */
#define BLACK 30
#define RED 31
#define GREEN 32
#define YELLOW 33
#define BLUE 34
#define MAGENTA 35
#define CYAN 36
#define WHITE 37

/* 배경색 */
#define B_BLACK 40
#define B_RED 41
#define B_GREEN 42
#define B_YELLOW 43
#define B_BLUE 44
#define B_MAGENTA 45
#define B_CYAN 46
#define B_WHITE 47

void setColor(int fore_color, int backg_color)
{
    printf("%c[%d;%dm", 0x1b, fore_color, backg_color);
}

void gotoxy(int x, int y)
{
    printf("%c[%d;%df", 0x1b, y, x);
}

int main(void)
{
    system("clear");

    setColor(RED, B_BLUE);
    gotoxy(30, 35);
    printf("Hello");

    setColor(RED, B_YELLOW);
    gotoxy(30, 38);
    printf("World");

    setColor(RESET, RESET);
    
    gotoxy(20, 19);
    printf("==========================================\n");

    for(int i = 0 + 20 ; i < 20 + 20 ; i++)
    {
        gotoxy(20, i);
        printf("||\n");

        gotoxy(60, i);
        printf("||\n");
    }

    gotoxy(20, 40);
    printf("==========================================\n");

    return 0;
}