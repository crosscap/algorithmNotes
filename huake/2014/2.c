#include <stdio.h>

#define MAXNUM 32

int bin2dec(char *);
void dec2bin(char *, int);

int main(void)
{
    char num1[MAXNUM], num2[MAXNUM], c;
    int number1, number2, calcul;

    scanf("%s %s %c", num1, num2, &c);
    number1 = bin2dec(num1);
    number2 = bin2dec(num2);
    switch (c)
    {
        case '+':
            calcul = number1 + number2;
            break;
        case '-':
            calcul = number1 - number2;
            break;
        case '*':
            calcul = number1 * number2;
            break;
        case '/':
            calcul = number1 / number2;
            break;
        default:
            break;
    }
    dec2bin(num1, calcul);
    puts(num1);

    return 0;
}

int bin2dec(char *num)
{
    int i;
    int sum, bin;

    for (i = 0; num[i]; i++)
        continue;
    i--;
    sum = 0;
    bin = 1;
    while (i >= 0)
    {
        if (num[i] == '1')
            sum += bin;
        bin *= 2;
        i--;
    }

    return sum;
}

void dec2bin(char *num, int dec)
{
    int i = 0, j;
    char temp;

    while (dec != 0)
    {
        num[i++] = dec % 2 + '0';
        dec /= 2;
    }
    num [i--] = '\0';
    for (j = 0; j < i; j++, i--)
    {
        temp = num[i];
        num[i] = num[j];
        num[j] = temp;
    }

    return;
}
