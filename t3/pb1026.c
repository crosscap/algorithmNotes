#include <stdio.h>

#define CLK_TCK 100

int main(void)
{
    int c1, c2, clock;
    int sec, min, hour, left;

    scanf("%d%d", &c1, &c2);
    clock = c2 - c1;
    sec = clock / CLK_TCK;
    left = clock % CLK_TCK;
    sec = (left >= CLK_TCK / 2) ? sec  + 1: sec;
    hour = sec / 3600;
    sec %= 3600;
    min = sec / 60;
    sec %= 60;
    printf("%02d:%02d:%02d", hour, min, sec);

    return 0;
}
