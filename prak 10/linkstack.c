#include <stdio.h>
#include <stdlib.h>
#include "linkstack.h"

void Alokasi(address *P, ElType X)
{
    *P = (address) malloc (sizeof(Node));
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

boolean IsEmpty(Stack S)
{
    return Top(S) == Nil;
}

void CreateEmpty(Stack *S)
{
    Top(*S) = Nil;
}

void Push(Stack *S, ElType X)
{
    address P;
    Alokasi(&P, X);
    if (P != Nil)
    {
        Next(P) = Top(*S);
        Top(*S) = P;
    }
}

void Pop(Stack *S, ElType *X)
{
    address P;
    *X = Info(Top(*S));
    P = Top(*S);
    if (Next(Top(*S)) == Nil)
    {
        CreateEmpty(S);
    }
    else
    {
        Top(*S) = Next(Top(*S));
    }
    free(P);
}

// void PrintInfo(Stack S)
// {
//     address P;
//     P = Top(S);
//     if (IsEmpty(S))
//     {
//         printf("[]");
//     }
//     else
//     {
//         printf("[");
//         while (P != Nil)
//         {
//             if (Next(P) != Nil)
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
//     Stack S;
//     address P;
//     ElType X;
//     CreateEmpty(&S);
//     Push(&S, 1);
//     Push(&S, 2);
//     Pop(&S, &X);
//     Pop(&S, &X);
//     PrintInfo(S); printf("\n");
// }