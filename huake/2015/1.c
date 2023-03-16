#include <stdio.h>
#include <ctype.h>

#define MAXSIZE 100

int main(void)
{
    int i, flag;
    char phone[MAXSIZE];

    flag = 0;
    gets(phone);
    for (i = 0; phone[i] != '\0'; i++)
        continue;
    if (i != 11)
        flag = 1;
    else if (phone[0] != '1')
        flag = 1;
    else
    {
        switch(phone[1])
        {
        case '3':
        case '5':
        case '6':
        case '8':
            for (i = 0; i < 11; i++)
                if (!isdigit(phone[i]))
                {
                    flag = 1;
                    break;
                }
            break;
        default:
            flag = 1;
            break;
        }
    }
    if (flag)
        printf("%s wrong", phone);
    else
        printf("%s right", phone);

    return 0;
}
