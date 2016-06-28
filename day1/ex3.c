#include <stdio.h>

int main(void)
{
	printf("\x1b[31m \x1b[5;10f");
	printf("HelloWorld\n");

    printf("\x1b[1;31m");
	printf("HelloWorld\n");
    
    printf("\x1b[33m");
	printf("HelloWorld\n");
    
    printf("\x1b[32m");
	printf("HelloWorld\n");
    
    printf("\x1b[34m");
	printf("HelloWorld\n");
    
    printf("\x1b[2;34m");
	printf("HelloWorld\n");
    
    printf("\x1b[0;35m");
	printf("HelloWorld\n");
    printf("\x1b[0m");

    return 0;
}