#include <stdio.h>
#include <string.h>

int main()
{
    char str[10];
    int i;
    int j;
    int jumlah = 0;
    scanf("%s", &str);
    for (i = 48; i <= 57; i++)
    {
        for (j = 0; j < strlen(str); j++)
        {
            if (str[j] == i)
            {
                jumlah = jumlah + 1;
            }
        }
        printf("%d", jumlah);
        jumlah = 0;
    }
    printf("\n");
    return 0;
}
