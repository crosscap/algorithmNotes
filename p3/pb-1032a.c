#include <stdio.h>
const int maxn = 1000010;
int school[maxn] = {0};

int main(void)
{
    int n, schID, score;
    int k = 1, max = -1;
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d%d", &schID, &score);
        school[schID] += score;
    }
    for (i = 1; i <= n; i++)
    {
        if (school[i] > max)
        {
            max = school[i];
            k = i;
        }
    }
    printf("%d %d\n", k, max);

    return 0;
}

