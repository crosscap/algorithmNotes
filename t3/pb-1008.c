#include <stdio.h>

#define MAXSIZE 100

void reserve(int *, int, int, int); /* 数组首地址, 数组总长, 首个逆置的偏移, 末尾逆置的偏移*/

int main(void)
{
    int i, n, m;
    int num[MAXSIZE];

    scanf("%d%d", &n, &m);
    for (i = 0; i < n; i++)
        scanf("%d", &num[i]);
    m %= n;
    reserve(num, n, 0, n-1);
    reserve(num, n, 0, m-1);
    reserve(num, n, m, n-1);


    for (i = 0; i < n; i++)
    {
        printf("%d", num[i]);
        if (n - 1 - i)
            putchar(' ');
    }
    putchar('\n');

    return 0;
}

void reserve(int *num, int n, int a, int b)
/* 逆置范围内的数组元素 */
/* 数组首地址, 数组总长, 首个逆置的偏移, 末尾逆置的偏移*/
{
    int temp;

    while (a < b)
    {
        temp = num[a];
        num[a] = num[b];
        num[b] = temp;
        a++;
        b--;
    }

    return;
}
