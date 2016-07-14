#include <stdio.h>
#include <math.h>

int main(void)
{
    printf("%f \r\n", sqrt(2.0));

    double vx, vy;
    vx = 1.0;
    vy = 1.0;

    double vLength = sqrt((vx * vx) + (vy * vy));
    printf("%f \r\n", vLength);

    printf("단위 벡터 : %f, %f\r\n", vx / vLength, vy / vLength);

    vx /= vLength;
    vy /= vLength;

    vLength = (vx * vx) + (vy * vy);

    printf("%f\r\n", vLength);

    return 0;
}