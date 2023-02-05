#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"

boolean IsEmpty(List L)
{
    return First(L) == Nil;
}

void CreateEmpty(List *L)
{
    First(*L) = Nil;
}

address Alokasi(infotype X)
{
    address P;
    P = (address) malloc (sizeof(ElmtList));
    if (P != Nil)
    {
        Info(P) = X;
        Next(P) = Nil;
    }
    return P;
}

void Dealokasi(address *P)
{
    free(*P);
}

address Search(List L, infotype X)
{
    if (IsEmpty(L))
    {
        return Nil;
    }
    else
    {
        address P;
        P = First(L);
        while (P != Nil)
        {
            if (Info(P) == X)
            {
                return P;
            }
            P = Next(P);
        }
        return Nil;
    }
}

void InsVFirst(List *L, infotype X)
{
    address First;
    First = Alokasi(X);
    InsertFirst(L, First);
}

void InsVLast(List *L, infotype X)
{
    address Last;
    Last = Alokasi(X);
    InsertLast(L, Last);
}

void DelVFirst(List *L, infotype *X)
{
    address Del;
    DelFirst(L, &Del);
    *X = Info(Del);
    Dealokasi(&Del);
}

void DelVLast(List *L, infotype *X)
{
    address P, Del;
    P = First(*L);
    if (Next(P) == Nil)
    {
        DelVFirst(L, X);
    }
    else
    {
        DelLast(L, &Del);
        *X = Info(Del);
        Next(P) = Nil;
    }
    Dealokasi(&Del);
}

void InsertFirst(List *L, address P)
{
    address First;
    First = First(*L);
    Next(P) = First;
    First(*L) = P;
}

void InsertAfter(List *L, address P, address Prec)
{
    address After;
    After = Next(Prec);
    Next(Prec) = P;
    Next(P) = After;
}

void InsertLast(List *L, address P)
{
    if (IsEmpty(*L))
    {
        InsertFirst(L, P);
    }
    else
    {
        address Last;
        Last = First(*L);
        while (Next(Last) != Nil)
        {
            Last = Next(Last);
        }
        Next(Last) = P;
    }
}

void DelFirst(List *L, address *P)
{
    *P = First(*L);
    First(*L) = Next(First(*L));
    Next(*P) = Nil;
}

void DelP(List *L, infotype X)
{
    if (!IsEmpty(*L))
    {
        address addressX, P, temp;
        addressX = Search(*L, X);
        if (addressX != Nil)
        {
            if (addressX != First(*L))
            {
                P = First(*L);
                while (Next(P) != addressX)
                {
                    P = Next(P);
                }
                DelAfter(L, &temp, P);
            }
            else
            {
                DelFirst(L, &temp);
            }
        }
    }
}

void DelLast(List *L, address *P)
{
    address Del;
    Del = First(*L);
    while (Next(Next(Del)) != Nil)
    {
        Del = Next(Del);
    }
    *P = Next(Del);
    Next(Del) = Nil;
}

void DelAfter(List *L, address *Pdel, address Prec)
{
    address P;
    *Pdel = Next(Prec);
    P = Next(*Pdel);
    Next(Prec) = P;
    Next(*Pdel) = Nil;
}

void PrintInfo(List L)
{
    if (IsEmpty(L))
    {
        printf("[]");
    }
    else
    {
        address P;
        P = First(L);
        printf("[");
        while (P != Nil)
        {
            if (Next(P) != Nil)
            {
                printf("%d,", Info(P));
            }
            else
            {
                printf("%d]", Info(P));
            }
            P = Next(P);
        }
    }
}

int NbElmt(List L)
{
    address P;
    int N = 0;
    P = First(L);
    while (P != Nil)
    {
        N++;
        P = Next(P);
    }
    return N;
}

infotype Max(List L)
{
    address P;
    P = First(L);

    infotype max;
    max = Info(P);
    while (P != Nil)
    {
        if (Info(P) > max)
        {
            max = Info(P);
        }
        P = Next(P);
    }
    return max;
}

address AdrMax(List L)
{
    address P;
    P = Search(L, Max(L));
    return P;
}

infotype Min(List L)
{
    address P;
    P = First(L);

    infotype min;
    min = Info(P);
    while (P != Nil)
    {
        if (Info(P) < min)
        {
            min = Info(P);
        }
        P = Next(P);
    }
    return min;
}

address AdrMin(List L)
{
    address P;
    P = Search(L, Min(L));
    return P;
}

float Average(List L)
{
    address P;
    P = First(L);

    float avg;
    avg = 0;

    while (P != Nil)
    {
        avg += Info(P);
        P = Next(P);
    }
    avg /= NbElmt(L);
    return avg;
}

void InversList(List *L)
{
    if (!IsEmpty(*L))
    {
        address P;
        address Prec = Nil;
        address Suc = Nil;
        
        P = First(*L);
        while (P != Nil)
        {
            Suc = Next(P);
            Next(P) = Prec;
            Prec = P;
            P = Suc;
        }
        First(*L) = Prec;
    }
}

void Konkat1(List *L1, List *L2, List *L3)
{
    address P;
    if (!IsEmpty(*L1) && !IsEmpty(*L2))
    {
        First(*L3) = First(*L1);
        P = First(*L3);

        while (Next(P) != Nil)
        {
            P = Next(P);
        }

        Next(P) = First(*L2);
    }
    else if (IsEmpty(*L1))
    {
        First(*L3) = First(*L2);
    }
    else if (IsEmpty(*L2))
    {
        First(*L3) = First(*L1);
    }
    First(*L1) = Nil;
    First(*L2) = Nil;
}
