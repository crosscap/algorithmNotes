#include <stdio.h>

#define MAXSIZE 1000

int main(void)
{
    int i, j;
    char num[MAXSIZE], str[MAXSIZE];

    gets(num);
    for (i = 0, j = 0; num[i+1]; i += 2, j++)
    {
        str[j] = (num[i] - '0') * 10 + (num[i+1] - '0') + 32;
    }
    if (num[i])
    {
        str[j] = (num[i] - '0') * 10 + 32;
        str[j + 1] = '\0';
    }
    else
        str[j] = '\0';
    puts(str);


    return 0;
}
