#include <stdio.h>

int main(void)
{
    int count_a, count_b;
    int da, db;
    long long a, b;

    scanf ("%lld%d%lld%d", &a, &da, &b, &db);

    for (count_a = 0; a != 0; a /= 10)
        if (a % 10 == da)
            count_a++;

    for (count_b = 0; b != 0; b /= 10)
        if (b % 10 == db)
            count_b++;
    a = b = 0;
    while (count_a)
    {
        a *= 10;
        a += (long long) da;
        count_a--;
    }
    while (count_b)
    {
        b *= 10;
        b += (long long) db;
        count_b--;
    }
    printf("%lld", a + b);

    return 0;
}
