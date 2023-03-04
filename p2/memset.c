#include <stdio.h>
#include <string.h>

int main(void)
{
    int i;
    int a[5] = {1, 2, 3, 4, 5};

    memset(a, 1, sizeof(a));
    for (i = 0; i < 5; i++){
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
