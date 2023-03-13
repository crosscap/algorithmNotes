#include <stdio.h>
#include <stdlib.h>

#define MAXNUM (1 << 31) - 1

int main(void)
{
    int points[7];
    int i, max, min;
    float sum;

    for (i = 0; i < 7; i++)
        scanf("%d", &points[i]);
    for (i = 0, max = 0, min = MAXNUM, sum = 0; i < 7; i++)
    {
        if (points[i] > max)
            max = points[i];
        if (points[i] < min)
            min = points[i];
        sum += (float)points[i];
    }
    sum -= (min + max);
    printf("%.1f", sum / 5.0);

    return 0;
}
