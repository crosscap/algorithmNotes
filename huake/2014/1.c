#include <stdio.h>

int main(void)
{
    int i, j, k, six_count, flag;

    for (i = 1000, six_count = 0; i< 10000; i++)
    {
        for (j = i, flag = 1; j != 0 && flag; j /= 10)
        {
            for (k = 2; k * k < j; k++)
            {
                if (j % k == 0)
                {
                    flag = 0;
                    break;
                }
            }
        }
        if (flag)
        {
            printf("%d", i);
            if (++six_count == 6)
            {
                putchar('\n');
                six_count = 0;
            }
            else
                putchar(' ');
        }
    }

    return 0;
}
