#include <stdio.h>

int main(void)
{
    int i, n;
    int a1, a2, b1, b2, sum;
    int ah, bh;

    scanf ("%d", &n);
    for (i = 0, ah = 0, bh = 0; i < n; i++)
    {
        scanf("%d%d%d%d", &a1, &a2, &b1, &b2);
        sum = a1 + b1;
        if (sum == a2 && sum != b2)
            bh++;
        if (sum != a2 && sum == b2)
            ah++;
    }
    printf("%d %d\n", ah, bh);

    return 0;
}
