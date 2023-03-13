#include <stdio.h>
#include <ctype.h>

#define IPMAXSIZE 16
#define IPMAXNUM 255

int main(void)
{
    char IPaddress[IPMAXSIZE];
    int i, j, num, point_num, flag = 0;

    gets(IPaddress);
    for (i = 0, flag = 0, point_num = 0; IPaddress[i] != '\0'; i++)
    {
        if (!(isdigit(IPaddress[i]) || IPaddress[i] =='.'))
        {
            flag = 1;
            break;
        }
        else if (IPaddress[i] =='.')
            point_num++;
    }
    if (point_num != 3)
        flag = 1;
    if (!flag)
    {
        for (i = 0, j = 0; i < 4 && !flag; i++)
        {
            num = 0;
            while (IPaddress[j] != '.' && IPaddress[j] !='\0')
            {
                num *= 10;
                num += IPaddress[j] - '0';
                j++;
            }
            j++;
            if (num > IPMAXNUM)
                flag = 1;
        }
    }
    if (flag)
        printf("%s wrong!", IPaddress);
    else
        printf("%s right!", IPaddress);

    return 0;
}
