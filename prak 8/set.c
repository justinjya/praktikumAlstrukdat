#include <stdio.h>
#include "set.h"

void CreateEmpty(Set *S)
{
    S->Count = Nil;
}

boolean IsEmpty(Set S)
{
    return S.Count == Nil;
}

boolean IsFull(Set S)
{
    return S.Count == MaxEl;
}

void Insert(Set *S, infotype Elmt)
{
    if (!IsFull(*S))
    {
        if (!IsMember(*S, Elmt))
        {
            S->Count++;
            S->Elements[S->Count - 1] = Elmt;
        }
    }
}

void Delete(Set *S, infotype Elmt)
{
    if (S->Count == 1)
    {
        S->Count = Nil;
    }
    else
    {
        if (IsMember(*S, Elmt))
        {
            int i = 0;
            while (i < S->Count && S->Elements[i] != Elmt)
            {
                i++;
            }
            while (i < S->Count)
            {
                S->Elements[i] = S->Elements[i + 1];
                i++;
            }
            S->Count--;
        }
    }
}

boolean IsMember(Set S, infotype Elmt)
{
    int i = 0;
    while (i < S.Count)
    {
        if (S.Elements[i] == Elmt)
        {
            return true;
        }
        i++;
    }
    return false;
}
