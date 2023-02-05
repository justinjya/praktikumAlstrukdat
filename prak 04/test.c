#include <stdio.h>
#include <stdlib.h>

// int main()
// {
//     int n = 5;
//     int *fibonacciArr;
//     fibonacciArr = (int*)malloc(n * sizeof(int));
//     fibonacciArr[0] = 1;
//     fibonacciArr[1] = 1;
//     int i, j;
//     for (i = 2; i <= n; i++)
//     {
//         fibonacciArr[i] = fibonacciArr[i-1] + fibonacciArr[i-2];
//     }
//     printf("result = [");
//     for (i = 0; i < n; i++)
//     {
//         printf("%d, ", fibonacciArr[i]);
//     }
//     printf("%d]", fibonacciArr[n]);
//     printf("\n");
//     printf("Nilai argumen result = %d", fibonacciArr[n]);
// }

// int main()
// {
//     int *T1;
//     int *T2;
//     T1 = (int*)malloc(4 * sizeof(int));
//     T1[0] = 1;
//     T1[1] = 2;
//     T1[2] = 3;
//     T1[3] = 4;
//     int i;
//     T2 = T1;
//     for (i = 0; i < 4; i++)
//     {
//         printf("%d", T2[i]);
//     }
//     free(T1);
//     free(T2);
// }

// int main()
// {
//     int *a[2];
//     int *b[3];
//     int *c[5];
//     a[0] = 1;
//     a[1] = 2;
//     b[0] = 3;
//     b[1] = 4;
//     b[2] = 5;
//     int i = 0;
//     int j = 0;
//     while (i < 5)
//     {
//         c[i] = a[i];
//         if (i > 1)
//         {
//             c[i] = b[j];
//             j++;
//         }
//         i++;
//     }
//     for (i = 0; i < 5; i++)
//     {
//         printf("%d:%d\n", i, c[i]);
//     }
// }

// int main()
// {
//     List L;
//     L = MakeList();
//     InsertFirst(&L, 1);
//     InsertLast(&L, 3);
//     InsertLast(&L, 9);
//     InsertLast(&L, 4);
//     InsertLast(&L, 8);
//     List minmax;
//     minmax = MinMax(L);
//     for (int i = 0; i < Length(minmax); i++)
//     {
//         printf("%d", minmax.A[i]);
//     }
// }

int main()
{
    char *nim = "18221016";
    printf("%s", nim);
}