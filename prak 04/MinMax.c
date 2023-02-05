#include <stdio.h>
#include "MinMax.h"

int Min(List L)
{
    int i;
    int min = L.A[0];
    for (i = 0; i < Length(L); i++)
    {
        if (L.A[i] < min)
        {
            min = L.A[i];
        }
    }
    return min;
}

int Max(List L)
{
    int i;
    int max = L.A[0];
    for (i = 0; i < Length(L); i++)
    {
        if (L.A[i] > max)
        {
            max = L.A[i];
        }
    }
    return max;
}

int iMin(List L)
{
    int i;
    for (i = 0; i < Length(L); i++)
    {
        if (L.A[i] == Min(L))
        {
            return i;
        }
    }
}

int iMax(List L)
{
    int i;
    for (i = 0; i < Length(L); i++)
    {
        if (L.A[i] == Max(L))
        {
            return i;
        }
    }
}

List MinMax(List L)
{
    List MinMax;
    MinMax = MakeList();
    if (Length(L) == 1)
    {
        return L;
    }
    else if (Length(L) == 2)
    {
        InsertFirst(&MinMax, Min(L));
        InsertAt(&MinMax, Max(L), 1);
        return MinMax;
    }
    else
    {
        InsertFirst(&MinMax, Min(L));
        InsertAt(&MinMax, Max(L), 1);
        DeleteAt(&L, iMin(L));
        DeleteAt(&L, iMax(L));
        List kons;
        kons = Concat(L, MinMax);
        return kons;
    }
}