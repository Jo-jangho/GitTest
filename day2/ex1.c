#include <stdio.h>

int main(void)
{
    char *code = "☆";
    printf("%3s %3x %3x", code, code[0], code[1]);

    return 0;
}