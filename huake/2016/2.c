#include <stdio.h>
#include <ctype.h>

#define MAXSIZE 100

int move(char *, int, int, int);

int main(void)
{
    char str[MAXSIZE + 1];
    int i, j, space_num, length;

    gets(str);
    for (i = 0, length = 0; str[i] != '\0'; i++, length++)
        continue;
    for (i = 0, space_num = 0; str[i] == ' '; i++, space_num++)
        continue;
    length = move(str, 0, space_num, length);
    i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == ' ')
        {
            for (space_num = 0, j = i; str[j] == ' '; j++, space_num++)
                continue;
            length = move(str, i + 1, space_num - 1, length);
        }
        else if (isalpha(str[i]) && isdigit(str[i + 1]) || isdigit(str[i]) && isalpha(str[i + 1]))
        {
            move(str, i+1, -1, length);
            length = str[i+1] = '_';
        }
        i++;
    }
    puts(str);

    return 0;
}

int move(char *str, int first, int num, int length)
{
    int i;

    if (num >= 0)
    {
        for (i = first; i + num < length; i++)
            str[i] = str[i + num];
        str[i] = '\0';
    }
    else
    {
        str[length + 1] = '\0';
        for (i = length; i > first; i--)
            str[i] = str[i + num];
    }

    return length - num;
}
