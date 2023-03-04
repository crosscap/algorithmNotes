#include <stdio.h>

int main(void)
{
    int i, j, n, row, col;
    char c;

    scanf("%d %c", &n, &c);

    col = n;
    row = n % 2 ? (n+1) / 2 : n / 2;

    for (i = 0; i < row; i++)
    {
        if (i == 0 || i == (row - 1) )
        {
            for (j = 0; j < col; j++)
                printf("%c", c);
            printf("\n");
        }
        else
        {
            printf ("%c", c);
            for (j = 1; j < col - 1; j++)
                printf(" ");
            printf("%c\n", c);
        }

    }
}
