#include <stdio.h>
#include <stdlib.h>
#include "listdp.h"

boolean IsEmpty(List L)
{
    return First(L) == Nil && Last(L) == Nil;
}

void CreateEmpty(List *L)
{
    First(*L) = Nil;
    Last(*L) = Nil;
}

address Alokasi(infotype X)
{
    address P;
    P = (address) malloc (sizeof(ElmtList));
    if (P != Nil)
    {
        Prev(P) = Nil;
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
    return P;
}

void InsVFirst(List *L, infotype X)
{
    address V;
    V = Alokasi(X);
    InsertFirst(L, V);
}

void InsVLast(List *L, infotype X)
{
    address V;
    V = Alokasi(X);
    InsertLast(L, V);
}

void DelVFirst(List *L, infotype *X)
{
    *X = Info(First(*L));
    DelP(L, *X);
}

void DelVLast(List *L, infotype *X)
{
    *X = Info(Last(*L));
    DelP(L, *X);
}

void InsertFirst(List *L, address P)
{
    if (IsEmpty(*L))
    {
        First(*L) = P;
        Last(*L) = P;
    }
    else
    {
        address First;
        First = First(*L);
        Next(P) = First;
        Prev(First) = P;
        First(*L) = P;
    }
}

void InsertLast(List *L, address P)
{
    if (IsEmpty(*L))
    {
        First(*L) = P;
        Last(*L) = P;
    }
    else
    {
        address Last;
        Last = Last(*L);
        Prev(P) = Last;
        Next(Last) = P;
        Last(*L) = P;
    }
}

void InsertAfter(List *L, address P, address Prec)
{
    if (Prec != Nil)
    {
        address After;
        After = Next(Prec);
        Next(P) = After;
        Prev(P) = Prec;
        Next(Prec) = P;
        Prev(After) = P;
    }
}

void InsertBefore(List *L, address P, address Succ)
{
    if (Succ != Nil)
    {
        address Before;
        Before = Prev(Succ);
        Next(P) = Succ;
        Prev(P) = Before;
        Next(Before) = P;
        Prev(Succ) = P;
    }
}

void DelFirst(List *L, address *P)
{
    if (!IsEmpty(*L))
    {
        *P = First(*L);
        if (Last(*L) != *P)
        {
            address NewFirst;
            NewFirst = Next(*P);
            Prev(NewFirst) = Nil;
            First(*L) = NewFirst;
            Next(*P) = Nil;
        }
        else
        {
            First(*L) = Nil;
            Last(*L) = Nil;
        }
    }
}

void DelLast(List *L, address *P)
{
    if (!IsEmpty(*L))
    {
        *P = Last(*L);
        if (First(*L) != *P)
        {
            address NewLast;
            NewLast = Prev(*P);
            Next(NewLast) = Nil;
            Last(*L) = NewLast;
            Prev(*P) = Nil;
        }
        else
        {
            First(*L) = Nil;
            Last(*L) = Nil;
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
            else if (P == Last(*L))
            {
                DelLast(L, &temp);
            }
            else
            {
                address Before, After;
                Before = Prev(P);
                After = Next(P);
                Prev(After) = Before;
                Next(Before) = After;
            }
            Dealokasi(P);
        }
    }
}

void DelAfter(List *L, address *Pdel, address Prec)
{
    if (!IsEmpty(*L))
    {
        if (Prec != Nil)
        {
            if (Next(Prec) != Nil)
            {
                if (Next(Prec) == Last(*L))
                {
                    DelLast(L, Pdel);
                }
                else
                {
                    *Pdel = Next(Prec);
                    address NewAfter;
                    NewAfter = Next(*Pdel);
                    Next(Prec) = NewAfter;
                    Prev(NewAfter) = Prec;
                    Prev(*Pdel) = Nil;
                    Next(*Pdel) = Nil;
                }
            }
        }
    }
}

void DelBefore(List *L, address *Pdel, address Succ)
{
    if (!IsEmpty(*L))
    {
        if (Succ != Nil)
        {
            if (Prev(Succ) != Nil)
            {
                if (Prev(Succ) == First(*L))
                {
                    DelFirst(L, Pdel);
                }
                else
                {
                    *Pdel = Prev(Succ);
                    address NewBefore;
                    NewBefore = Prev(*Pdel);
                    Prev(Succ) = NewBefore;
                    Next(NewBefore) = Succ;
                    Prev(*Pdel) = Nil;
                    Next(*Pdel) = Nil;
                }
            }
        }
    }
}

void PrintForward(List L)
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

void PrintBackward(List L)
{
    if (IsEmpty(L))
    {
        printf("[]");
    }
    else
    {
        address Last, P;
        Last = First(L);
        while (Next(Last) != Nil)
        {
            Last = Next(Last);
        }
        P = Last;
        printf("[");
        while (P != Nil)
        {
            if (Prev(P) != Nil)
            {
                printf("%d,", Info(P));
            }
            else
            {
                printf("%d]", Info(P));
            }
            P = Prev(P);
        }
    }
}

int main()
{
    List L;
    infotype X;
    address P, temp, temp1;
    CreateEmpty(&L);
    InsVFirst(&L, 3);
    InsVFirst(&L, 2);
    InsVFirst(&L, 1);
    InsVLast(&L, 5);
    InsVLast(&L, 7);
    
    temp = Alokasi(6);
    temp1 = Search(L, 5);
    InsertAfter(&L, temp, temp1);

    temp = Alokasi(4);
    temp1 = Search(L, 5);
    InsertBefore(&L, temp, temp1);

    DelFirst(&L, &P);
    DelLast(&L, &P);

    DelP(&L, 4);

    printf("Before Del:\n");
    temp1 = Search(L, 3);
    DelAfter(&L, &temp, temp1);
    temp1 = Search(L, 6);
    DelBefore(&L, &temp ,temp1);
    PrintForward(L);
    printf("\n");
    PrintBackward(L);

    printf("\n\n");
    printf("After Del:\n");
    // DelFirst(&L, &temp);
    // DelFirst(&L, &temp);
    // DelLast(&L, &temp);
    // DelLast(&L, &temp);
    // DelVFirst(&L, &X);
    // DelVFirst(&L, &X);
    DelVLast(&L, &X);
    // DelVLast(&L, &X);
    // printf("IsEmpty(L) = %d\n", IsEmpty(L));
    PrintForward(L);
    printf("\n");
    PrintBackward(L);
    printf("\n");
    // printf("temp = %p, Info(temp) = %d\n", temp, Info(temp));
    printf("X = %d\n", X);
}