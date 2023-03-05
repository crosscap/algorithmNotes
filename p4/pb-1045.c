#include <stdio.h>
#define MAXSIZE 100000
#define MAXNUM 1000000000
int main(void)
{
    int i, min, max, length, count;
    int num[MAXSIZE+1], Lmax[MAXSIZE], flag[MAXSIZE] = {0};

    scanf("%d", &length);
    for (i = 0; i < length; i++)
        scanf("%d", &num[i]);
    for (i = 0, max = 0; i < length; i++)
    {
        if (num[i] > max)
            max = num[i];
        Lmax[i] = max;
    }
    for (i = length-1, min = MAXNUM, count = 0; i >= 0; i--)
    {
        if (num[i] < min)
            min = num[i];
        if (min >= num[i] && Lmax[i] <= num[i])
        {
            flag[i] = 1;
            count++;
        }
    }
    printf("%d\n", count);
    for (i = 0, count = 0; i < length; i++)
    {
        if (flag[i])
            if (!count)
            {
                printf("%d", num[i]);
                count = 1;
            }
            else
                printf(" %d", num[i]);
    }
    printf("\n");

    return 0;
}
