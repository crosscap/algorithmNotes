#include <stdio.h>
#define MAXSIZE 81

void reserve(char *s, int a, int b);

int main(void)
{
    int i, j, length;
    char str[MAXSIZE] = { 0 };

    gets(str);
    for (length = 0; str[length]; length++)
        continue;
    reserve(str, 0, length-1);
    for (i = 0; i < length; i++)
    {
        for (j = i; str[j] != ' ' && str[j] != '\0'; j++)
            continue;
        reserve(str, i, j-1);
        i = j;
    }
    puts(str);

    return 0;
}

void reserve(char *s, int a, int b)
{
    char temp;
    while (a < b)
    {
        temp = s[a];
        s[a++] = s[b];
        s[b--] = temp;
    }
}
