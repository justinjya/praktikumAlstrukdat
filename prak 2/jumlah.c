#include <stdio.h>

int main()
{
    int x, digit, jumlah;
    jumlah = 0;
    scanf("%d", &x);
    while (x > 0)
    {
        digit = x % 10;
        jumlah += digit;
        x = x / 10;
    }
    printf("%d\n", jumlah);
    return 0;
}