#include <stdio.h>
#include <string.h>

int main(void)
{
    char* ptr = strdup("move position 30, 20");
    char* ptrTemp;

    ptrTemp = strtok(ptr, " ");

    printf("%s \n", ptrTemp);
    printf("%s \n", strtok(NULL, " "));

    ptrTemp = strtok(NULL, " ");
    printf("%s \n", ptrTemp);

    printf("%s \n", strtok(NULL, " "));

    return 0;
}