#include <stdio.h>

int main(void)
{
    int a, b, d, add, i, num;
    char tran[31];

    scanf("%d%d%d", &a, &b, &d);

    add = a + b;
    if (add == 0)
        printf("0\n");
    else
    {
        for (i = 0, num = 0; add; add /= d, i++, num++)
            tran[i] = (add % d) + '0';
        for (i = num; i; i--)
            printf("%c", tran[i-1]);
        printf("\n", tran);
    }

    return 0;
}
