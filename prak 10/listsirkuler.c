#include <stdio.h>
#include <stdlib.h>
#include "listsirkuler.h"

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

void Dealokasi(address P)
{
    free(P);
}

address Search(List L, infotype X)
{
    if (IsEmpty(L))
    {
        return Nil;
    }
    else
    {
        address P, Last;
        Last = First(L);
        while (Next(Last) != First(L))
        {
            Last = Next(Last);
        }
        P = First(L);
        while (P != Last)
        {
            if (Info(P) == X)
            {
                return P;
            }
            P = Next(P);
        }
        if (Info(Last) == X)
        {
            return Last;
        }
        return Nil;
    }
}

void InsVFirst(List *L, infotype X)
{
    address V;
    V = Alokasi(X);
    if (V != Nil)
    {
        InsertFirst(L, V);
    }
}

void InsVLast(List *L, infotype X)
{
    address V;
    V = Alokasi(X);
    if (V != Nil)
    {
        InsertLast(L, V);
    }
}

void DelVFirst(List *L, infotype *X)
{
    if (!IsEmpty(*L))
    {
        *X = Info(First(*L));
        DelP(L, *X);
    }
}

void DelVLast(List *L, infotype *X)
{
    if (!IsEmpty(*L))
    {
        address Last;
        Last = First(*L);
        while (Next(Last) != First(*L))
        {
            Last = Next(Last);
        }
        *X = Info(Last);
        DelP(L, *X);
    }
}

void InsertFirst(List *L, address P)
{
    if (IsEmpty(*L))
    {
        First(*L) = P;
        Next(P) = First(*L);
    }
    else
    {
        address Last;
        Last = First(*L);
        while (Next(Last) != First(*L))
        {
            Last = Next(Last);
        }
        Next(P) = First(*L);
        First(*L) = P;
        Next(Last) = First(*L);
    }
}

void InsertLast(List *L, address P)
{
    if (IsEmpty(*L))
    {
        First(*L) = P;
        Next(P) = First(*L);
    }
    else
    {
        address Last;
        Last = First(*L);
        while (Next(Last) != First(*L))
        {
            Last = Next(Last);
        }
        Next(P) = First(*L);
        Next(Last) = P;
    }
}

void InsertAfter(List *L, address P, address Prec)
{
    if (Prec != Nil)
    {
        address After, Before;
        After = Next(Prec);
        Before = First(*L);
        while (Before != Prec)
        {
            Before = Next(Before);
        }
        Next(Before) = P;
        Next(P) = After;
        Next(Prec) = P;
    }
}

void DelFirst(List *L, address *P)
{
    if (!IsEmpty(*L))
    {
        *P = First(*L);
        if (Next(*P) == First(*L))
        {
            First(*L) = Nil;
        }
        else
        {
            address Last;
            Last = First(*L);
            while (Next(Last) != First(*L))
            {
                Last = Next(Last);
            }
            First(*L) = Next(*P);
            Next(Last) = First(*L);
            Next(*P) = Nil;
        }
    }
}

void DelLast(List *L, address *P)
{
    if (!IsEmpty(*L))
    {
        address NewLast;
        NewLast = First(*L);
        if (Next(NewLast) == First(*L))
        {
            First(*L) = Nil;
        }
        else
        {
            while (Next(Next(NewLast)) != First(*L))
            {
                NewLast = Next(NewLast);
            }
        }
        *P = Next(NewLast);
        Next(NewLast) = First(*L);
        Next(*P) = Nil;
    }
}

void DelAfter(List *L, address *Pdel, address Prec)
{
    if (!IsEmpty(*L))
    {
        if (Prec != Nil)
        {
            if (Next(Prec) != First(*L))
            {
                if (Next(Prec) != First(*L))
                {
                    *Pdel = Next(Prec);
                    address After;
                    After = Next(*Pdel);
                    Next(Prec) = After;
                    Next(*Pdel) = Nil;
                }
                else
                {
                    DelFirst(L, Pdel);
                }
            }
            else
            {
                First(*L) = Nil;
            }
        }
    }
}

void DelP(List *L, infotype X)
{
    if (!IsEmpty(*L))
    {
        address P, temp;
        P = Search(*L, X);
        if (P != Nil)
        {
            if (P == First(*L))
            {
                DelFirst(L, &temp);
            }
            else
            {
                address Before;
                Before = First(*L);
                while (Next(Before) != P)
                {
                    Before = Next(Before);
                }
                DelAfter(L, &temp, Before);
            }
        }
    }
}

void PrintInfo(List L)
{
    if (IsEmpty(L))
    {
        printf("[]");
    }
    else
    {
        address P, Last;
        Last = First(L);
        while (Next(Last) != First(L))
        {
            Last = Next(Last);
        }
        P = First(L);
        printf("[");
        while (P != Last)
        {
            printf("%d,", Info(P));
            P = Next(P);
        }
        printf("%d]", Info(P));
    }
}
