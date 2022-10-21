#include <stdio.h>

int main()
{
    int n, p, i, j;
    scanf("%d", &n);
    p = (2 * n) - 1;
    for (j = 0; j < p; j++)
    {
        for (i = 0; i < p; i++)
        {
            if (j % 2 == 0)
            {
                if (i % 2 == 0)
                {
                    printf("O");
                }
                else
                {
                    printf("X");
                }
            }
            else
            {
                if (i % 2 == 0)
                {
                    printf("X");
                }
                else
                {
                    printf("O");
                }
            }
        }
        printf("\n");
    }
    return 0;
}