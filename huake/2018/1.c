#include <stdio.h>
#define MAXSIZE 100

int main(void)
{
    int i, space_flag, max, last_max;
    int word, alpha, alphabate[26] = {0};
    char sentence[MAXSIZE+1];

    gets(sentence);
    for (i = word = alpha = space_flag = 0; sentence[i] != '\0'; i++)
    {
        if (sentence[i] >= 'a' && sentence[i] <= 'z' || sentence[i] >= 'A' && sentence[i] <= 'Z')
        {
            alpha++;
            if (sentence[i] >= 'a' && sentence[i] <= 'z')
                alphabate[sentence[i] - 'a']++;
            else if (sentence[i] >= 'A' && sentence[i] <= 'Z')
                alphabate[sentence[i] - 'A']++;
            if (space_flag == 0)
            {
                word++;
                space_flag = 1;
            }
        }
        else if (sentence[i] == ' ')
            space_flag = 0;
    }
    for (i = 0, max = 0; i < 26; i++)
        if (alphabate[i] > max)
            max = alphabate[i];
    printf("字母个数: %d\n单词个数: %d\n最多的字母: ", alpha, word);
    for (last_max = 25; alphabate[last_max] != max; last_max--)
        continue;
    for (i = 0; i <= last_max; i++)
    {
        if (alphabate[i] == max)
        {
            putchar('a' + i);
            if (i != last_max)
                printf(", ");
            else
                putchar('\n');
        }
    }
    printf("出现的次数: %d\n", max);

    return 0;
}
