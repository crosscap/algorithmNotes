#include <stdio.h>
#include <stdlib.h>

#define MAXNUM 50

int main(void)
{
    char number[MAXNUM+1];
    int count[10];
    int i, j;

    for (i = 0; i < 10; i++)
        scanf("%d", &count[i]);
    for (i = 1; i < 10; i++)
        if (count[i])
        {
            count[i]--;
            number[0] = i + '0';
            break;
        }

    for (i = 0, j = 1; i < 10;)
    {
        if (count[i])
        {
            count[i]--;
            number[j] = i + '0';
            j++;
        }
        else
            i++;
    }
    number[j] = '\0';
    puts(number);

    return 0;
}