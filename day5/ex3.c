#include <stdio.h>

int main(void)
{
    /**/
    int num[] = {3, 6, 4, 5, 7 };
    int* pNum = num;
    int sum = 0;
    int max = 0;
    int min = 100;
    const int MAX_SIZE = sizeof(num) / sizeof(int);

    /**/
    for(int i = 0 ; i < MAX_SIZE ; i++)
    {
        sum += *(pNum + i);

        if(max < *(pNum + i))
        {
            max = *(pNum + i);
        }
                                                                              
        if(min > *(pNum + i))
        {
            min = *(pNum + i);
        }
    }

    /**/
    printf("배열의 합 : %d\n", sum);

    printf("배열의 최대값 : %d\n", max);

    printf("배열의 최소값 : %d\n", min); 

    return 0;
}