#include <stdio.h>

void exchange(char** pA, char** pB)
{
    char* pT;
    pT = *pA;
    *pA = *pB;
    *pB = pT;
}

int main(void)
{
    int val = 10;
    int* pI;
    pI = &val;

    char* pA = "success";
    char* pB = "failed";

    printf("pA : %s, pB : %s\n", pA, pB);

    exchange(&pA, &pB);

    printf("pA : %s, pB : %s\n", pA, pB);

    return 0;
} 