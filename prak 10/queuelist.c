#include <stdio.h>
#include <stdlib.h>
#include "queuelist.h"

void Alokasi(address *P, infotype X)
{
    *P = (address) malloc (sizeof(ElmtQueue));
    if (P != Nil)
    {
        Info(*P) = X;
        Next(*P) = Nil;
    }
}

void Dealokasi(address P)
{
    free(P);
}

boolean IsEmpty(Queue Q)
{
    return Head(Q) == Nil && Tail(Q) == Nil;
}

int NbElmt(Queue Q)
{
    address P;
    int N;
    P = Head(Q);
    N = 0;
    while (P != Nil)
    {
        N++;
        P = Next(P);
    }
    return N;
}

void CreateEmpty(Queue *Q)
{
    Head(*Q) = Nil;
    Tail(*Q) = Nil;
}

void Enqueue(Queue *Q, infotype X)
{
    address P;
    Alokasi(&P, X);
    if (P != Nil)
    {
        if (IsEmpty(*Q))
        {
            Head(*Q) = P;
            Tail(*Q) = P;
        }
        else
        {
            Next(Tail(*Q)) = P;
            Tail(*Q) = P;
        }
    }
}

void Dequeue(Queue *Q, infotype *X)
{
    address P;
    *X = Info(Head(*Q));
    P = Head(*Q);
    if (NbElmt(*Q) == 1)
    {
        CreateEmpty(Q);
    }
    else
    {
        Head(*Q) = Next(Head(*Q));
    }
    free(P);
}

// void PrintInfo(Queue Q)
// {
//     address P;
//     P = Head(Q);
//     if (IsEmpty(Q))
//     {
//         printf("[]");
//     }
//     else
//     {
//         printf("[");
//         while (P != Nil)
//         {
//             if (P != Tail(Q))
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
//     Queue Q;
//     address P;
//     infotype X;
//     CreateEmpty(&Q);
//     Enqueue(&Q, 1);
//     Enqueue(&Q, 2);
//     Enqueue(&Q, 3);
//     Dequeue(&Q, &X);
//     // Dequeue(&Q, &X);
//     // Dequeue(&Q, &X);
//     PrintInfo(Q);
//     printf("\n");
//     // printf("P = %p, Info(P) = %d, Next(P) = %p\n", P, Info(P), Next(P));
// }