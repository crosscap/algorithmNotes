#include <stdio.h>

#define MAXNUM 100000
#define MOD 1000000007

int main(void)
{
    int i, count, length, sum;
    char str[MAXNUM+1];
    int Pnum[MAXNUM];

    gets(str);
    for (i = 0; str[i]; i++);
    length = i;
    for (i = 0, count = 0; i < length; i++)
    {
        if (str[i] == 'P')
            count++;
        Pnum[i] = count;
    }
    for (i = length-1, count = 0, sum = 0; i; i--)
    {
        if (str[i] == 'T')
            count++;
        else if (str[i] == 'A')
            sum += Pnum[i] * count;
        sum %= MOD;
    }

    printf("%d\n", sum);

    return 0;
}
