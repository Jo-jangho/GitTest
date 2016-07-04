#include <stdio.h>

int main(void)
{
    char word[20];

    word[0] = 'h';
    word[1] = 'i';
    word[4] = 0x00;

    printf("%s\n", word);

    return 0;
}