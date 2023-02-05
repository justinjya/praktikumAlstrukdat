#include <stdio.h>
#include <stdlib.h>
#include "linkdummy.h"

boolean IsEmpty(List L)
{
    return Info(First(L)) == 0 && Info(Last(L)) == 0;
}

void MakeEmpty(List *L)
{
    address dummy = Alokasi(0);
    if (dummy != Nil)
    {
        First(*L) = dummy;
        Last(*L) = dummy;
    }
    else
    {
        First(*L) = Nil;
        Last(*L) = Nil;
    }
}

address Alokasi(ElType X)
{
    address P;
    P = (address) malloc (sizeof(Node));
    if (P != Nil)
    {
        Info(P) = X;
        Next(P) = Nil;
    }
}

void Dealokasi(address P)
{
    free(P);
}

address Search(List L, ElType X)
{
    address P;
    P = First(L);
    while (P != Last(L))
    {
        if (Info(P) == X)
        {
            return P;
        }
        P = Next(P);
    }
    return Nil;
}

void InsertFirst(List *L, ElType X)
{
    address P;
    P = Alokasi(X);
    if (P != Nil)
    {
        Next(P) = First(*L);
        First(*L) = P;
    }
}

void InsertLast(List *L, ElType X)
{
    if (IsEmpty(*L))
    {
        InsertFirst(L, X);
    }
    else
    {
        address P, Last;
        P = Alokasi(X);
        if (P != Nil)
        {     
            Last = First(*L);
            while (Next(Last) != Last(*L))
            {
                Last = Next(Last);
            }
            Next(P) = Next(Last);
            Next(Last) = P;
        }
    }
}

void DeleteFirst(List *L, ElType *X)
{
    *X = Info(First(*L));
    address P;
    P = First(*L);
    First(*L) = Next(First(*L));
    Dealokasi(P);
}

void DeleteLast(List *L, ElType *X)
{
    address Last, pLast;
    Last = First(*L);
    while (Next(Last) != Last(*L))
    {
        Last = Next(Last);
    }
    *X = Info(Last);
    if (Last == First(*L))
    {
        MakeEmpty(L);
    }
    else
    {
        pLast = First(*L);
        while (Next(pLast) != Last)
        {
            pLast = Next(pLast);
        }
        Next(pLast) = Last(*L);
    }
    Dealokasi(Last);
}

// void PrintInfo(List L)
// {
//     address P;
//     P = First(L);
//     if (IsEmpty(L))
//     {
//         printf("[]");
//     }
//     else
//     {
//         printf("[");
//         while (P != Last(L))
//         {
//             if (Next(P) != Last(L))
//             {
//                 printf("%d," , Info(P));
//             }
//             else
//             {
//                 printf("%d]", Info(P));
//             }
//             P = Next(P);
//         }
//     }
// }

// int main()
// {
//     List L;
//     address P;
//     ElType X;
//     MakeEmpty(&L);
//     InsertFirst(&L, 1);
//     InsertLast(&L, 2);
//     // InsertLast(&L, 3);
//     // DeleteFirst(&L, &X);
//     // DeleteFirst(&L, &X);
//     // DeleteFirst(&L, &X);
//     // DeleteFirst(&L, &X);
//     // DeleteLast(&L, &X);
//     // DeleteLast(&L, &X);
//     // DeleteLast(&L, &X);
//     // DeleteLast(&L, &X);
//     // PrintInfo(L); printf("\n");
//     // printf("Search = %p\n", Search(L, 2));
// }