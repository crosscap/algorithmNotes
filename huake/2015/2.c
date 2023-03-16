#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

int cmp(const void *, const void *);

int main(void)
{
    int i, j, length1, length2;
    char str1[MAXSIZE+1], str2[MAXSIZE+1], str[2*MAXSIZE+1];

    scanf("%s %s", str1, str2);
    for (i = 0; str1[i] != '\0'; i++)
        str[i] = str1[i];
    for (j = 0; str2[j] != '\0'; i++, j++)
        str[i] = str2[j];
    str[i] = '\0';
    puts(str);
    for (i = 0, j = 0; str[i] != '\0' && str[i + 1] != '\0'; i += 2, j++)
    {
        str1[j] = str[i];
        str2[j] = str[i + 1];
    }
    str2[j] = '\0';
    length2 = j;
    if (str[i])
        str1[j++] = str[i];
    str1[j] = '\0';
    length1 = j;
    printf("%s %s\n", str1, str2);
    qsort(str1, length1, sizeof(char), cmp);
    qsort(str2, length2, sizeof(char), cmp);
    printf("%s %s\n", str1, str2);

    return 0;
}

int cmp(const void *a, const void *b)
{
    return (*(char *)a - *(char *)b);
}
