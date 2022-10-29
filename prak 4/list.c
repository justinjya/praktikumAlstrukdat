#include <stdio.h>
#include "list.h"

List MakeList()
{
    List L;
    IdxType i;
    for (i = 0; i < MaxEl; i++)
    {
        L.A[i] = Mark;
    }
    return L;
}

boolean IsEmpty(List L)
{
    return L.A[0] == Mark;
}

ElType Get(List L, IdxType i)
{
    return L.A[i];
}

void Set(List *L, IdxType i, ElType v)
{
    L->A[i] = v;
}

int Length(List L)
{
    IdxType i = 0;
    
    while (L.A[i] != Mark)
    {
        i++;
    }
    return i;
}

IdxType FirstIdx(List L)
{
    return 0;
}

IdxType LastIdx(List L)
{
    return Length(L)-1;
}

boolean IsIdxValid(List L, IdxType i)
{
    return (i >= 0 && i < MaxEl);
}

boolean IsIdxEff(List L, IdxType i)
{
    return (i >= FirstIdx(L) && i <= LastIdx(L));
}

boolean Search(List L, ElType X)
{
    IdxType i;
    boolean found = false;
    for (i = FirstIdx(L); i <= LastIdx(L); i++)
    {
        if (X == L.A[i])
        {
            found = true;
        }
    }
    return found;
}

void InsertFirst(List *L, ElType X)
{
    IdxType i;
    for (i = LastIdx(*L); i >= 0; i--)
    {
        L->A[i] = L->A[i-1];
    }
    L->A[0] = X;
}

void InsertAt(List *L, ElType X, IdxType i)
{
    IdxType j;
    for (j = LastIdx(*L) + 1; j >= i; j--)
    {
        L->A[j] = L->A[j-1];
    }
    L->A[i] = X;
}

void InsertLast(List *L, ElType X)
{
    L->A[LastIdx(*L) + 1] = X;
}

void DeleteFirst(List *L)
{
    IdxType i;
    for (i = FirstIdx(*L); i <= LastIdx(*L); i++)
    {
        L->A[i] = L->A[i+1];
    }
}

void DeleteAt(List *L, IdxType i)
{
    IdxType j;
    for (j = i; j <= LastIdx(*L); j++)
    {
        L->A[j] = L->A[j+1];
    }
}

void DeleteLast(List *L)
{
    L->A[LastIdx(*L)] = Mark;
}

List Concat(List L1, List L2)
{
    List Concat;
    Concat = MakeList();
    IdxType i = FirstIdx(L1);
    IdxType j = FirstIdx(L2);
    while (i < (Length(L1) + Length(L2)))
    {
        Concat.A[i] = L1.A[i];
        if (i > LastIdx(L1))
        {
            Concat.A[i] = L2.A[j];
            j++;
        }
        i++;
    }
    return Concat;
}
