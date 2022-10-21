#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int N, q, l, r;
    scanf("%d", &N);
    int *Arr1;
    Arr1 = (int*)malloc(N * sizeof(int));
    int *Arr2;
    Arr2 = (int*)malloc(pow(10,3) * sizeof(int));
    for (int j = 0; j < N; j++)
    {
        scanf("%d", &q);
        Arr1[j] = q;
    }
    int j = 0;
    while (j < pow(10,3))
    {
        if (j % N == 0)
        {
            Arr2[j] = Arr1[0];
        }
        else if (j >= N)
        {
            Arr2[j] = Arr1[j % N];
        }
        else
        {
            Arr2[j] = Arr1[j];
        }
        j++;
    }
    scanf("%d", &q);
    int *Arr3;
    Arr3 = (int*)malloc(q * sizeof(int));
    for (int i = 0; i < q; i++)
    {
        int jumlah = 0;
        scanf("%d %d", &l, &r);
        for (int j = l-1; j <= r-1; j++)
        {
            jumlah += Arr2[j];
        }
        Arr3[i] = jumlah;
    }
    for (int i = 0; i < q; i++)
    {
        printf("%d\n", Arr3[i]);
    }
    return 0;
}