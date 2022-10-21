#include <stdio.h>
#include <stdlib.h>
#include "arrayMhs.h"

void MakeEmpty(TabMhs *T)
{
    T->Neff = 0;
}

int NbElmt(TabMhs T)
{
    return T.Neff;
}

int MaxNbEl(TabMhs T)
{
    return IdxMax - IdxMin + 1;
}

IdxType GetFirstIdx(TabMhs T)
{
    return IdxMin;
}

IdxType GetLastIdx(TabMhs T)
{
    return T.Neff;
}

ElType GetElmt(TabMhs T, IdxType i)
{
    return T.TI[i];
}

void SetTab(TabMhs Tin, TabMhs *Tout)
{
    for(int i = IdxMin; i <= Tin.Neff; i++)
    {
        Tout->TI[i] = Tin.TI[i];
    }
}

void SetEl (TabMhs *T, IdxType i, ElType v)
{
    T->TI[i] = v;
    if (T->Neff < i)
    {
        T->Neff = i;
    }
}

void SetNeff(TabMhs *T, IdxType N)
{
    T->Neff = N;
}

boolean IsIdxValid(TabMhs T, IdxType i)
{
    if ((i >= IdxMin) && (i <= IdxMax))
    {
        return true;
    }
    else
    {
        return false;
    }
}

boolean IsIdxEff(TabMhs T, IdxType i)
{
    if ((i >= IdxMin) && (i <= T.Neff))
    {
        return true;
    }

    else
    {
        return false;
    }
}

boolean IsEmpty(TabMhs T)
{
    if (T.Neff > 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

boolean IsFull(TabMhs T)
{
    if (T.Neff == IdxMax)
    {
        return true;
    }

    else
    {
        return false;
    }
}

void TulisIsi(TabMhs T)
{
    if (IsEmpty(T) == true)
    {
        printf("Tabel kosong\n");
    }
    else
    {
        for (int i = IdxMin; i <= T.Neff; i++)
        {
            printf("%s | %s | %.2f\n", T.TI[i].nama, T.TI[i].nim, T.TI[i].nilai);
        }
    }
}

ElType MakeMahasiswa(char *Nama, char *NIM, float Nilai)
{
    ElType Mhs;
    Mhs.nama = Nama;
    Mhs.nim = NIM;
    Mhs.nilai = Nilai;
    return Mhs;
}

float RataRata(TabMhs T)
{
    int i;
    float jumlah, rata;
    for (i = IdxMin; i <= T.Neff; i++)
    {
        jumlah += T.TI[i].nilai;
    }
    rata = jumlah / T.Neff;
    return rata;
}

float Max(TabMhs T)
{
    int i;
    float max;
    max = T.TI[IdxMin].nilai;
    for (i = IdxMin; i <= T.Neff; i++)
    {
        if (T.TI[i].nilai > max)
        {
            max = T.TI[i].nilai;
        }
    }
    return max;
}

float Min(TabMhs T)
{
    int i;
    float min;
    min = T.TI[IdxMin].nilai;
    for (i = IdxMin; i <= T.Neff; i++)
    {
        if (T.TI[i].nilai < min)
        {
            min = T.TI[i].nilai;
        }
    }
    return min;
}

char *MaxNama(TabMhs T)
{
    int i, j;
    j = IdxMin;
    TabMhs temp;
    MakeEmpty(&temp);
    for (i = IdxMin; i <= T.Neff; i++)
    {
        if (T.TI[i].nilai == Max(T))
        {
            SetEl(&temp, j ,T.TI[i]);
            SetNeff(&temp, j);
            j++;
        }
    }
    int nimMin = IdxMin;
    for (i = IdxMin; i <= temp.Neff; i++)
    {
        if (atoi(temp.TI[i].nim) < atoi(temp.TI[nimMin].nim))
        {
            nimMin = i;
        }
    }
    return temp.TI[nimMin].nama;
}

char *MinNama(TabMhs T)
{
    int i, j;
    j = IdxMin;
    TabMhs temp;
    MakeEmpty(&temp);
    for (i = IdxMin; i <= T.Neff; i++)
    {
        if (T.TI[i].nilai == Min(T))
        {
            SetEl(&temp, j ,T.TI[i]);
            SetNeff(&temp, j);
            j++;
        }
    }
    int nimMin = IdxMin;
    for (i = IdxMin; i <= temp.Neff; i++)
    {
        if (atoi(temp.TI[i].nim) < atoi(temp.TI[nimMin].nim))
        {
            nimMin = i;
        }
    }
    return temp.TI[nimMin].nama;
}

int JumlahJurusan(TabMhs T, char *Jurusan)
{
    int count, i;
    count = 0;
    for (i = IdxMin; i <= T.Neff; i++)
    {
        if ((T.TI[i].nim[0] == Jurusan[0]) &&
            (T.TI[i].nim[1] == Jurusan[1]) &&
            (T.TI[i].nim[2] == Jurusan[2]))
        {
            count++;
        }
    }
    return count;
}