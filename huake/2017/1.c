#include <stdio.h>

int main(void)
{
    int i, j, row, cal;
    char c;

    c = getchar();
    if (c >= 'A' && c <= 'Z')
    {
        row = c - 'A' + 1;
        c = 'A';
    }
    else
    {
        row = c - 'a' + 1;
        c = 'a';
    }
    for (i = 0, cal = row - 1; i < row; i++, cal--)
    {
        for (j = 0; j < i; j++)
            putchar(' ');
        for (j = 0; j < cal; j++)
            printf("%c", c + j);
        for (; j >= 0; j--)
            printf("%c", c + j);
        putchar('\n');
    }

    return 0;
}
