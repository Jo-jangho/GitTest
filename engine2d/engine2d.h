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

char *pMapBuf;

/* 글자 색 바꾸기 */
void setColor(int fore_color, int backg_color);

/* 글자 위치 바꾸기 */
void gotoxy(int x, int y);

/* 사각형 그리기 */
void drawMyBox(int nXpos, int nYpos, int nWidth, int nHeight, int nForColor, int nBack_Color);

/* 자동차 그리기 */
void drawMyCar(int nXpos, int nYpos);

/* 타일맵 */
void map_printCell(int rawData);

/* 전체맵 */
void map_drawAll(int *pMap);

void putTile(int sy, int ey, int sx, int ex, int width, char *ptrBuf);

void readMap();

/**/
int kbhit();

int getch();

struct termios orig_termios;

void reset_terminal_mode();

void set_conio_terminal_mode();

#endif