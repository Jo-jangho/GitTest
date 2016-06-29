#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
void setColor(int fore_color, int backg_color);

/* 글자 위치 바꾸기 */
void gotoxy(int x, int y);

/*
////
*/
int main(void)
{
    /**/
    int nRand_Fore = 0;
    int nRand_Back = 0;

    srand((int)time(NULL));

    /**/
    system("clear");

    /**/
    setColor(RED, B_BLUE);
    gotoxy(40, 35);
    printf("Hello");

    setColor(RED, B_YELLOW);
    gotoxy(40, 38);
    printf("World");

    /**/
    setColor(RESET, RESET);
    
    /**/
    gotoxy(20, 19);  // 위쪽 벽
    for(int i = 0 ; i < 42 ; i++)
    {
        nRand_Fore = rand() % 7 + 30;
        nRand_Back = rand() % 7 + 40;
        setColor(nRand_Fore, nRand_Back);
        printf("=");
        setColor(RESET, RESET);
    }

    for(int i = 0 + 20 ; i < 20 + 20 ; i++)
    {
        nRand_Fore = rand() % 7 + 30;
        nRand_Back = rand() % 7 + 40;
        setColor(nRand_Fore, nRand_Back);

        gotoxy(20, i);  // 왼쪽 벽
        printf("||");

        gotoxy(60, i);  // 오른쪽 벽
        printf("||\n");

        setColor(RESET, RESET);  
    }

    gotoxy(20, 40);  // 아래쪽 벽
    for(int i = 0 ; i < 42 ; i++)
    {
        nRand_Fore = rand() % 7 + 30;
        nRand_Back = rand() % 7 + 40;
        setColor(nRand_Fore, nRand_Back);
        printf("=");
    }

    /**/
    setColor(RESET, RESET);    

    return 0;
}

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