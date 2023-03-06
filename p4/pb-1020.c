#include <stdio.h>
#include <stdlib.h>

#define MAXNUM 1000

int cmp(const void *, const void *);

typedef struct mooncake
{
    double total;
    double sell;
    double price;
} mooncake;

int main(void)
{
    int i, mc_num;
    double need;
    double sum = 0;
    mooncake mooncakes[MAXNUM];

    scanf("%d %lf", &mc_num, &need);
    for (i = 0; i < mc_num; i++)
        scanf("%lf", &mooncakes[i].total);
    for (i = 0; i < mc_num; i++)
    {
        scanf("%lf", &mooncakes[i].sell);
        mooncakes[i].price = mooncakes[i].sell / mooncakes[i].total;
    }
    qsort(mooncakes, mc_num, sizeof(mooncake), cmp);
    for (i = 0; need != 0 && i < mc_num; i++)
    {
        if (mooncakes[i].total <= need)
        {
            need -= mooncakes[i].total;
            sum += mooncakes[i].sell;
        }
        else
        {
            sum += mooncakes[i].price * need;
            need = 0;
        }
    }
    printf("%.2f\n", sum);

    return 0;
}

int cmp(const void *a, const void *b)
{
    return ((mooncake*)b)->price > ((mooncake*)a)->price;
}
