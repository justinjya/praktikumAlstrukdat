#include <stdio.h>

// int main()
// {
//     int bil;
//     scanf("%d", &bil);
//     if ((bil > 2) && (bil % 2 == 0))
//     {
//         printf("Ya\n");
//     }
//     else
//     {
//         printf("Tidak\n");
//     }
//     return 0;
// }

// int main()
// {
//     int n, m, i, j, jumlah;
//     scanf("%d", &n);
//     int temp[n];
//     for (i = 0; i < n; i++)
//     {
//         jumlah = 0;
//         scanf("%d", &m);
//         for (j = 1; j <= m; j++)
//         {
//             if (j % 7 == 0)
//             {
//                 jumlah += j;
//             }
//             else if (j % 10 == 7)
//             {
//                 jumlah += j;
//             }
//             else if (j / 10 == 7)
//             {
//                 jumlah += j;
//             }
//         }
//         temp[i] = jumlah;
//     }
//     for (i = 0; i < n; i++)
//     {
//         printf("%d\n", temp[i]);
//     }
//     return 0;
// }

int main()
{
    int n, m, i, j, jumlah, temp;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        jumlah = 0;
        scanf("%d", &m);
        for (j = 1; j <= m; j++)
        {
            if (j % 7 == 0)
            {
                jumlah += j;
            }
            else if (j % 10 == 7)
            {
                jumlah += j;
            }
            else
            {   
                temp = j;
                while (temp > 0)
                {
                    temp /= 10;
                    if (temp % 10 == 7)
                    {
                        jumlah += j;
                    }
                }
            }
        }
        printf("%d\n", jumlah);
    }
    return 0;
}