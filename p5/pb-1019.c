#include <stdio.h>
#include <stdlib.h>

int cmplow(const void *, const void *);
int cmphigh(const void *, const void *);

int main(void)
{
    int i, num, low, high;
    int mid[4];

    scanf("%d", &num);

    if (num == 0)
        printf("0000 - 0000 = 0000\n");
    else if (num == 6174)
        printf("7641 - 1467 = 6174\n");
    else
    {
        while (num != 0 && num != 6174)
        {
            low = high = 0;
            for (i = 3; i >= 0; i--, num /= 10)
                mid[i] = num % 10;
            qsort(mid, 4, sizeof(int), cmplow);
            for (i = 0; i < 4; i++)
                low = low * 10 + mid[i];
            qsort(mid, 4, sizeof(int), cmphigh);
            for (i = 0; i < 4; i++)
                high = high * 10 + mid[i];
            num = high - low;
            printf("%04d - %04d = %04d\n", high, low, num);
        }
    }
}

int cmplow(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

int cmphigh(const void *a, const void *b)
{
    return *(int*)b - *(int*)a;
}
