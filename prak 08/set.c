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


Set SetUnion(Set s1, Set s2)
{
    Set s3;
    CreateEmpty(&s3);

    address i = 0;
    address j = 0;
    while (i < s1.Count)
    {
        Insert(&s3, s1.Elements[i]);
        i++;
    }
    while (j < s2.Count)
    {
        Insert(&s3, s2.Elements[j]);
        j++;
    }
    return s3;
}

Set SetIntersection(Set s1, Set s2)
{
    Set s3;
    CreateEmpty(&s3);

    for (address i = 0; i < s1.Count; i++)
    {
        for (address j = 0; j < s2.Count; j++)
        {
            if (s1.Elements[i] == s2.Elements[j])
            {
                Insert(&s3, s1.Elements[i]);
            }
        }
    }
    return s3;
}

Set SetSymmetricDifference(Set s1, Set s2)
{
    Set uni, intersect, s3;

    uni = SetUnion(s1, s2);
    intersect = SetIntersection(s1, s2);
    s3 = SetSubtract(uni, intersect);
    
    return s3;
}

Set SetSubtract(Set s1, Set s2)
{
    Set s3;
    CreateEmpty(&s3);

    for (address i = 0; i < s1.Count; i++)
    {
        Insert(&s3, s1.Elements[i]);
    }
    for (address i = 0; i < s1.Count; i++)
    {
        for (address j = 0; j < s2.Count; j++)
        {
            if (s1.Elements[i] == s2.Elements[j])
            {
                Delete(&s3, s1.Elements[i]);
            }
        }
    }
    return s3;
}
