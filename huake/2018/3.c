#include <stdio.h>
#define MAXNUM 65535

int main(void)
{
    int out, i, j, n, d, int_num, zero_num, flag;
    int xunhuanjie[MAXNUM];
    long long tran;

    for (out = 0; out < 3; out++)
    {
        scanf("%d/%d", &n, &d);
        if (d == 0)
        {
            printf("error!\n");
        }
        else if (d == 1)
            printf("%d/%d=%d\n", n, d, n);
        else
        {
            for (int_num = 0; n >= d; int_num++)
                n -= d;
            if (n == 0)
                printf("%d/%d=%d\n", int_num * d, d, int_num);
            else    // 此时最极端的情况为1/65535
            {
                tran = (long long) n;   // 应对1/65535这样的极端情况，防止计算过程中溢出
                tran *= 10;
                for (zero_num = 0; tran < d; tran *= 10, zero_num++)
                    continue;
                for (i = 0, flag = 1; flag; i++)
                {
                    xunhuanjie[i] = (int) (tran / (long long)d);
                    for (j = 0; j < i; j++)
                        if (xunhuanjie[j] == xunhuanjie[i])
                        {
                            flag = 0;
                            break;
                        }
                    tran = (tran % (long long)d) * 10;
                }
                printf("%d.", int_num);
                for (; zero_num > 0; zero_num--)
                    putchar('0');
                for (zero_num = 0; zero_num < j; zero_num++)
                    printf("%d", xunhuanjie[zero_num]);
                i = i - 1;
                if (xunhuanjie[i] != 0)
                {
                    putchar('(');
                    for (; j < i; j++)
                        printf("%d", xunhuanjie[j]);
                    putchar(')');
                }
                printf("\n");
            }
        }
    }

    return 0;
}
