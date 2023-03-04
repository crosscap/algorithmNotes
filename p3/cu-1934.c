#include <stdio.h>
#define MAXSIZE 200

int main(void)
{
    int i, n, x, flag;
    int num[MAXSIZE] = { 0 };

    while(scanf("%d", &n) != EOF)
    {
        flag = 0;
        for (i = 0; i < n; i++)
            scanf("%d", &num[i]);
        scanf("%d", &x);
        for (i = 0; i < n; i++)
            if (x == num[i])
            {
                flag = 1;
                break;
            }
        if (flag)
            printf ("%d\n", i);
        else
            printf ("-1\n");
    }
    

    return 0;
}
