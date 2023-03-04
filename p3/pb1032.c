#include <stdio.h>
#define MAXSIZE 100001
int point_sum[MAXSIZE] = { 0 };

int main(void)
{
    int i, num;
    int no, point, max_no, max_point;
    scanf("%d", &num);

    for (i = 0; i < num; i++)
    {
        scanf("%d %d", &no, &point);
        point_sum[no] += point;
    }
    max_no = 0;
    max_point = -1;
    for (i = 1; i < MAXSIZE; i++)
    {
        if (point_sum[i] > max_point)
        {
            max_point = point_sum[i];
            max_no = i;
        }
    }
    printf("%d %d\n", max_no, max_point);

    return 0;
}
