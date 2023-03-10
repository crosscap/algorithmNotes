#include <stdio.h>

int main(void)
{
    char twl[9] = {0};
    int ten[8], bin[32] = {0};
    int i, last_num, basic, sum, eight_flag;

    gets(twl);
    for (i = 8; twl[i] == '\0'; i--)
        continue;
    last_num = i;
    for (i = 0; i <= last_num; i++)
    {
        if (twl[i] != 'a' && twl[i] != 'b')
            ten[i] = twl[i] - '0';
        else
            ten[i] = twl[i] - 'a' + 10;
    }
    for (i = 0; i <= last_num; i++)
        if (i != last_num)
            printf("%d ", ten[i]);
        else
            printf("%d\n", ten[i]);
    for (i = last_num, basic = 1, sum = 0; i >= 0; i--)
    {
        sum += ten[i] * basic;
        basic *= 12;
    }
    printf("%d\n", sum);
    i = 31;
    while (sum)
    {
        bin[i] = sum % 2;
        sum /= 2;
        i--;
    }

    for (eight_flag = 0, i = 0; i < 32; i++)
    {
        printf("%d", bin[i]);
        eight_flag++;
        if (eight_flag == 8)
        {
            putchar(' ');
            eight_flag = 0;
        }
    }

    return 0;
}
