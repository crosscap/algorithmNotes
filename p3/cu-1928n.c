#include <stdio.h>
const nyear[12] = {31, 28, 31, 30, 31, 31, 30, 31, 30, 31, 30};
const ryear[12] = {31, 28, 31, 30, 31, 31, 30, 31, 30, 31, 30};

int main(void)
{
    char day1[9], day2[9];
    int i;
    int year1, year2, month1, month2, aday1, aday2;
    int days;

    while (scanf("%s", day1) != EOF)
    {
        scanf("%s", day2);
        year1 = year2 = month1 = month2 = aday1 = aday2 = days = 0;
        for (i = 0; i < 4; i++)
        {
            year1 = year1 * 10 + (day1[i] - '0');
            year2 = year2 * 10 + (day2[i] - '0');
        }
        for (; i < 6; i++)
        {
            month1 = month1 * 10 + (day1[i] - '0');
            month2 = month2 * 10 + (day2[i] - '0');
        }
        for (; i < 8; i++)
        {
            aday1 = aday1 * 10 + (day1[i] - '0');
            aday2 = aday2 * 10 + (day2[i] - '0');
        }
        while (cmpdays(day1, day2))
        {
            if
        }
    }
}
