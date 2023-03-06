#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b);

int main(void)
{
    int m, n;

    while (scanf("%d %d", &m, &n) != EOF)
    {
        if (m > n)
            printf("%d\n", gcd(m, n));
        else
            printf("%d\n", gcd(n, m));
    }
}

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}
