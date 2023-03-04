#include <stdio.h>

int main()
{
    int n, num;

    n = 0;
    scanf("%d", &num);
    while (num != 1)
    {
        if (num % 2)
            num = ( num * 3 + 1 ) / 2;
        else
            num /= 2;
        n++;
    }
    printf("%d\n", n);

    return 0;
}
