#include <stdio.h>
#include "listlinier.h"

int main()
{
    List L, tempOp;
    infotype N, Q, op;
    address opAddress, P, temp, tempOpAddress;

    CreateEmpty(&L);
    CreateEmpty(&tempOp);
    scanf("%d", &N);
    scanf("%d", &Q);
    for (infotype i = 1; i <= N; i++)
    {
        InsVLast(&L, i);
    }

    for (infotype i = 0; i < Q; i++)
    {
        scanf("%d", &op);
        InsVLast(&tempOp, op);
    }

    tempOpAddress = First(tempOp);
    while (tempOpAddress != Nil)
    {
        opAddress = Search(L, Info(tempOpAddress));
        if (opAddress != Nil)
        {
            P = First(L);
            if (opAddress != First(L))
            {
                while (Next(P) != opAddress)
                {
                    P = Next(P);
                }
                DelAfter(&L, &temp, P);
                InsertFirst(&L, temp);
            }
            printf("hit ");
            PrintInfo(L);
            printf("\n");
        }
        else
        {
            DelLast(&L, &temp);
            InsVFirst(&L, Info(tempOpAddress));
            printf("miss ");
            PrintInfo(L);
            printf("\n");
        }
        tempOpAddress = Next(tempOpAddress);
    }
    return 0;
}