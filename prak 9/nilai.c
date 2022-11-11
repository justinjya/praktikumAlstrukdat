#include <stdio.h>
#include "listlinier.h"

int main()
{
    List L;
    List Invers;
    CreateEmpty(&L);
    CreateEmpty(&Invers);

    infotype nilai = 0;
    while (nilai >= 0 && nilai <= 100)
    {   
        scanf("%d", &nilai);
        if (nilai >= 0 && nilai <= 100)
        {
            InsVFirst(&L, nilai);
        }
    }

    address P;
    P = First(L);
    while (P != Nil)
    {
        InsVFirst(&Invers, Info(P));
        P = Next(P);
    }

    if (IsEmpty(L))
    {
        printf("Daftar nilai kosong\n");
    }
    else
    {
        printf("%d\n", NbElmt(L));
        printf("%d\n", Max(L));
        printf("%d\n", Min(L));
        printf("%.2f\n", Average(L));
        PrintInfo(Invers);
        printf("\n");
        PrintInfo(L);
        printf("\n");
    }
}