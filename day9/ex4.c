#include <stdio.h>

int main(void)
{
    int test = 0x00000001;
    
    test = test << 1;
    printf("%x \n", test);

    test = test << 1;
    printf("%x \n", test);

    test = test << 1;
    printf("%x \n", test);

    test = test << 1;
    printf("%x \n", test);

    test = test << 1;
    printf("%x \n", test);

    test = test << 1;
    printf("%x \n", test);

    test = test << 1;
    printf("%x \n", test);

    return 0;
}