#include <stdio.h>

int main(void)
{
    FILE* pFile;
    pFile = fopen("test.txt", "w+");

    fprintf(pFile, "%d, %s\n", 100, "hello");

    fclose(pFile);

    pFile = fopen("test.txt", "r");
    char szStr[128];
    int num;

    fscanf(pFile, "%d, %s\n", &num, szStr);
    printf("%d, %s\n", num, szStr);

    return 0;
}