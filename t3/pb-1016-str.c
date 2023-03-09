#include <stdio.h>
int main(void)
{
    char a[10] = {0}, b[10] = {0};
    int da, db;
    int numa = 0, numb = 0;
    int i;

    scanf("%s %d %s %d", a, &da, b, &db);
    i = 0;
    while (a[i])
    {
        if ((a[i] - '0') == da)
            numa = numa  * 10 + da;
        ++i;
    }
    i = 0;
    while (b[i])
    {
        if ((b[i] - '0') == db)
            numb = numb  * 10 + db;
        ++i;
    }
    printf("%d", numa + numb);

    return 0;
}