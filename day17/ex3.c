#include <stdio.h>

int main(void)
{
    // 선언
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[5] = {0, };
    int j = 4;

    // 바꾸기
    for(int i = 0 ; i < 5 ; i++)
    {
        arr2[i] = arr1[j--];
    }

    // 출력
    for(int i = 0 ; i < 5 ; i++)
    {
        printf("%3d", arr1[i]);
    }
    puts("");
    for(int i = 0 ; i < 5 ; i++)
    {
        printf("%3d", arr2[i]);
    }

    return 0;
}