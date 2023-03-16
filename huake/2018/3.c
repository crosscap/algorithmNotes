#include <stdio.h>
#define MAXNUM 100000

int main(void)
{
    int out, i, j, n, d, int_num, zero_num, flag, tran;
    int looper[MAXNUM], looper_l, looper_r;

    for (out = 0; out < 3; out++)
    {
        scanf("%d/%d", &n, &d);
        if (d == 0)
        {
            printf("error!\n");
        }
        else if (d == 1)
        {
            printf("%d/%d=%d\n", n, d, n);
        }
        else
        {
             printf("%d/%d=", n, d);
            for (int_num = 0; n >= d; int_num++)
                n -= d;
            if (n == 0)
                printf("%d/%d=%d\n", int_num * d, d, int_num);
            else    // 此时最极端的情况为1/65535
            {
                tran = n;   // 应对1/65535这样的极端情况，int类型不会发生溢出
                tran *= 10;
                for (zero_num = 0; tran < d; tran *= 10, zero_num++)
                    continue;
                for (i = 0, flag = 1; flag; i++)
                {
                    looper[i] = tran;
                    for (j = 0; j < i; j++)
                    {
                        if (looper[j] == looper[i])
                        {
                            flag = 0;
                            break;
                        }
                    }
                    tran = (tran % d) * 10;
                }
                looper_l = j;
                looper_r = i - 1;
                printf("%d.", int_num);
                for (; zero_num > 0; zero_num--)
                {
                    putchar('0');
                }
                for (i = 0; i < looper_l; i++)
                {
                    printf("%d", looper[i] / d);
                }
                if (looper[looper_r] != 0)
                {
                    putchar('(');
                    for (i = looper_l; i < looper_r; i++)
                    {
                        printf("%d", looper[i] / d);
                    }
                    putchar(')');
                }
                putchar('\n');
            }
        }
    }

    return 0;
}
