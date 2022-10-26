#include <stdio.h>

int main()
{
    int bil;
    scanf("%d", &bil);
    if ((bil > 2) && (bil % 2 == 0))
    {
        printf("Ya\n");
    }
    else
    {
        printf("Tidak\n");
    }
    return 0;
}
