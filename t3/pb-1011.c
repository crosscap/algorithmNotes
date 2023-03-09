#include <stdio.h>

typedef struct number_part
{
    long long a, b, c;
} number_part;

int main(void)
{
    number_part number;
    int i, num;
    long long sum;

    scanf("%d", &num);
    for (i = 0; i < num; i++)
    {
        scanf("%lld%lld%lld", &number.a, &number.b, &number.c);
        if (number.a + number.b > number.c)
            printf("Case #%d: true\n", i + 1);
        else
            printf("Case #%d: false\n", i + 1);
    }

    return 0;
}
