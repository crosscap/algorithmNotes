#include <stdio.h>

#define MAXSIZE 100

int hex_judge(char *);
int obj_judge(char *);
int dec_judge(char *);

int main(void)
{
    char num[MAXSIZE+1];
    int flag;

    while (scanf("%s", num) != EOF)
    {
        if (num[0] == '0' && (num[1] == 'x' || num[1] == 'X'))
            flag = hex_judge(num);
        else if (num[0] == '0')
            flag = obj_judge(num);
        else
            flag = dec_judge(num);
        if (flag)
            printf("YES\n");
        else
            printf("No\n");
    }


    return 0;
}

int hex_judge(char *num)
{
    int i, flag = 1;

    for (i = 2; num[i] && flag; i++)
    {
        if (!((num[i] >= '0' && num[i] <= '9') ||
              (num[i] >= 'a' && num[i] <= 'f') ||
              (num[i] >= 'A' && num[i] <= 'F')))
        {
            if (num[i] == 'u' || num[i] == 'U')
            {
                if ((num[i+1] != 'l' && num[i+1] != 'L') && (num[i+1] != '\0'))
                {
                    flag = 0;
                }
            }
            else if (num[i] == 'l' || num[i] == 'L')
            {
                if (num[i+1] != '\0')
                {
                    flag = 0;
                }
            }
            else
            {
                flag = 0;
            }
        }
    }

    return flag;
}

int obj_judge(char *num)
{
    int i, flag = 1;

    for (i = 1; num[i] && flag; i++)
    {
        if (!(num[i] >= '0' && num[i] <= '7'))
        {
            if (num[i] == 'u' || num[i] == 'U')
            {
                if ((num[i+1] != 'l' && num[i+1] != 'L') && (num[i+1] != '\0'))
                {
                    flag = 0;
                }
            }
            else if (num[i] == 'l' || num[i] == 'L')
            {
                if (num[i+1] != '\0')
                {
                    flag = 0;
                }
            }
            else
            {
                flag = 0;
            }
        }
    }

    return flag;
}

int dec_judge(char *num)
{
    int i, flag = 1;

    for (i = 0; num[i] && flag; i++)
    {
        if (!(num[i] >= '0' && num[i] <= '9'))
        {
            if (num[i] == 'u' || num[i] == 'U')
            {
                if ((num[i+1] != 'l' && num[i+1] != 'L') && (num[i+1] != '\0'))
                {
                    flag = 0;
                }
            }
            else if (num[i] == 'l' || num[i] == 'L')
            {
                if (num[i+1] != '\0')
                {
                    flag = 0;
                }
            }
            else
            {
                flag = 0;
            }
        }
    }

    return flag;
}
