#include <stdio.h>
#include <stdlib.h>
#include "arraydin.h"

ArrayDin MakeArrayDin()
{
    ArrayDin Arr;
    Arr.A = (ElType *)malloc(InitialSize * sizeof(ElType));
    Arr.Capacity = InitialSize;
    Arr.Neff = 0;
    return Arr;
}

void DeallocateArrayDin(ArrayDin *array)
{
    free(array->A);
}

boolean IsEmpty(ArrayDin array)
{
    return array.Neff == 0;
}

int Length(ArrayDin array)
{
    return array.Neff;
}

ElType Get(ArrayDin array, IdxType i)
{
    return array.A[i];
}

int GetCapacity(ArrayDin array)
{
    return array.Capacity;
}

void InsertAt(ArrayDin *array, ElType el, IdxType i)
{
    if (array->Neff == array->Capacity)
    {
        array->Capacity *= 2;
        array->A = (ElType *)realloc(array->A, array->Capacity * sizeof(ElType));
    }
    int temp = array->Neff;
    while (temp > i)
    {
        array->A[temp] = array->A[temp - 1];
        temp--;
    }
    array->A[i] = el;
    array->Neff++;
}

void InsertLast(ArrayDin *array, ElType el)
{
    InsertAt(array, el, array->Neff);
}

void InsertFirst(ArrayDin *array, ElType el)
{
    InsertAt(array, el, 0);
}

void DeleteAt(ArrayDin *array, IdxType i)
{
    int temp = i;
    while (temp < array->Neff - 1)
    {
        array->A[temp] = array->A[temp + 1];
        temp++;
    }
    array->Neff--;
}

void DeleteLast(ArrayDin *array)
{
    array->Neff--;
}

void DeleteFirst(ArrayDin *array)
{
    DeleteAt(array, 0);
}

void PrintArrayDin(ArrayDin array)
{
    if (array.Neff == 0)
    {
        printf("[]\n");
    }
    else
    {
        int i;
        printf("[");
        for (i = 0; i < array.Neff - 1; i++)
        {
            printf("%d, ", array.A[i]);
        }
        printf("%d]\n", array.A[array.Neff - 1]);
    }
}

void ReverseArrayDin(ArrayDin *array)
{
    int i = array->Neff - 1;
    int count = 0;
    int temp;
    while (count < i)
    {
        temp = array->A[count];
        array->A[count] = array->A[i];  
        array->A[i] = temp;
        count++;
        i--;
    }
}

ArrayDin CopyArrayDin(ArrayDin array)
{
    ArrayDin ArrCopy;
    ArrCopy = MakeArrayDin();
    int i;
    for (i = 0; i < array.Neff; i++)
    {
        InsertLast(&ArrCopy, array.A[i]);
    }
    return ArrCopy;
}

IdxType SearchArrayDin(ArrayDin array, ElType el)
{
    int i;
    for (i = 0; i < array.Neff; i++)
    {
        if (array.A[i] == el)
        {
            return i;
        }
    }
    return -1;
}