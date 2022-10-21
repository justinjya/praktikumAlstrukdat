#include <stdio.h>
#include <stdlib.h>
#include "fibonacci.h"

int fibonacci(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

void fibonacci1(int n, int *result)
{
    *result = fibonacci(n);
}

int fibonacci2(int n)
{
    return fibonacci(n);
}

void fibonacci3(int n, int *result)
{
    int i;
    for (i = 0; i <= n; i++)
    {
        result[i] = fibonacci(i);
    }
}