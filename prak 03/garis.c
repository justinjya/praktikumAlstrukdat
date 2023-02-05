#include <stdio.h>
#include <math.h>
#include "garis.h"

void MakeGARIS(POINT P1, POINT P2, GARIS *L)
{
    GARIS garis;
    PAwal(*L) = P1;
    PAkhir(*L) = P2;
}

void BacaGARIS(GARIS *L)
{
    POINT P1, P2;
    int valid = 0;
    while (valid < 1)
    {
        BacaPOINT(&P1);
        BacaPOINT(&P2);
        if (EQ(P1, P2))
        {
            printf("Garis tidak valid\n");
        }
        else
        {
            MakeGARIS(P1, P2, L);
            valid = 1;
        }
    }
}

void TulisGARIS(GARIS L)
{
    printf("(");
    TulisPOINT(PAwal(L));
    printf(",");
    TulisPOINT(PAkhir(L));
    printf(")");
}

float PanjangGARIS(GARIS L)
{
    return Panjang(PAwal(L), PAkhir(L));
}

float Gradien(GARIS L)
{
    float gradien;
    gradien = (Ordinat(PAkhir(L)) - Ordinat(PAwal(L))) / (Absis(PAkhir(L)) - Absis(PAwal(L)));
    return gradien;
}

boolean IsTegakLurus(GARIS L1, GARIS L2)
{
    return Gradien(L1) * Gradien(L2) == -1;
}

boolean isSejajar(GARIS L1, GARIS L2)
{
    return Gradien(L1) == Gradien(L2);
}