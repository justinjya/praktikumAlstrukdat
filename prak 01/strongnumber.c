#include <stdio.h>

int main()
{
    int bil, temp, i, jumlah;
    jumlah = 0;
    scanf("%d", &bil);
    temp = bil;
    while (temp > 0)
    {
        int digit = temp % 10;
        int hasil = 1;
        for (i = 1; i <= digit; i++)
        {
            hasil = i * hasil;
        }
        jumlah = jumlah + hasil;
        temp = temp / 10;
    }
    if (jumlah == bil)
    {
        printf("Y\n");
    }
    else
    {
        printf("N\n");
    }
    return 0;
}