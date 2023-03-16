#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

int ASCII[128] = {0};
const char reverse[16] = {0x0, 0x8, 0x4, 0xc, 0x2, 0xa, 0x6, 0xe, 0x1, 0x9, 0x5, 0xd, 0x3, 0xb, 0x7, 0xf};

int main(void)
{
    int i;
    char trans, low, str[MAXSIZE];

    gets(str);
    puts(str);
    for (i = 0; str[i] != '\0'; i++)
    {
        if (ASCII[str[i]] == 0)
        {
            ASCII[str[i]] = 1;
            putchar(str[i]);
        }
    }
    putchar('\n');
    for (i = 0; str[i] != '\0'; i++)
    {
        if ((str[i] >= '0' && str[i] <= '9') ||
            (str[i] >= 'a' && str[i] <= 'f') ||
            (str[i] >= 'A' && str[i] <= 'F'))
        {
            trans = str[i];
            low = trans & 0x0f;
            low = reverse[low];
            trans &= 0xf0;
            trans |= low;
            if (trans >= 'a' && trans <= 'z')
                trans = trans - 'a' + 'A';
            putchar(trans);
        }
    }
    putchar('\n');

    return 0;
}
