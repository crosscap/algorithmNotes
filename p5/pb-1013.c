#include <stdio.h>

#define MAXNUM 10000

int main(void)
{
    int i, j, m, n, flag;
    int prime[MAXNUM] = { 0 };

    scanf("%d%d", &m, &n);
    prime[0] = 2;
    for (i = 3; prime[n-1] == 0; i++)
    {
        for (j = 0, flag = 0; prime[j] != 0; j++)
        {
            if (i % prime[j] == 0)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            prime[j] = i;
    }
    for (i = m - 1; i < n; i++)
        if ((i - m + 2) % 10 != 0 && i != n - 1)
            printf("%d ", prime[i]);
        else
            printf("%d\n", prime[i]);

    return 0;
}
