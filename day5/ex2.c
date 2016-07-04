#include <stdio.h>

int main(void)
{
    int num [] = { 3, 7, 15, 6, 8, 2};
    int sum = 0;
    int max = 0;
    int min = 100;

    /**/
    printf("배열의 갯수는 : %d\n", sizeof(num) / sizeof(int));


    /**/
    for(int i = 0 ; i < sizeof(num) / sizeof(int) ; i++)
    {
        sum += num[i];
        
        if(max < num[i])
        {
            max = num[i];
        }

        if(min > num[i])
        {
            min = num[i];
        }
    }

    /**/
    printf("배열의 합 : %d\n", sum);

    printf("배열의 최대값 : %d\n", max);

    printf("배열의 최소값 : %d\n", min); 
    
    return 0;
}