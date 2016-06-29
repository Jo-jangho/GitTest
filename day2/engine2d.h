#ifndef __ENGINE_2D__
#define __ENGINE_2D__

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

/* 글자 색 바꾸기 */
void setColor(int fore_color, int backg_color)
{
    printf("%c[%d;%dm", 0x1b, fore_color, backg_color);
}

/* 글자 위치 바꾸기 */
void gotoxy(int x, int y)
{
    printf("%c[%d;%df", 0x1b, y, x);
}

#endif