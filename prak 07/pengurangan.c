#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main()
{
    Stack S1;
    Stack S2;
    Stack S3;
    CreateEmpty(&S1);
    CreateEmpty(&S2);
    CreateEmpty(&S3);

    char *s1;
    char *s2;
    s1 = (char*) malloc (100 * sizeof(char));
    s2 = (char*) malloc (100 * sizeof(char));
    scanf("%s", s1);
    scanf("%s", s2);

    while (*s1 != '\0')
    {
        Push(&S1, *s1 - 48);
        s1++;
    }
    while (*s2 != '\0')
    {
        Push(&S2, *s2 - 48);
        s2++;
    }

    infotype angka1;
    infotype angka2;
    infotype hitung;
    boolean negatif = false;

    if (Top(S1) > Top(S2)) // s1 lebih besar dar s2
    {
        while (!IsEmpty(S2))
        {
            Pop(&S1, &angka1);
            Pop(&S2, &angka2);
            if (angka1 < angka2)
            {
                angka1 += 10;
                InfoTop(S1) -= 1;
            }
            hitung = angka1 - angka2;
            Push(&S3, hitung);
        }

        while (!IsEmpty(S1))
        {
            Pop(&S1, &angka1);
            Push(&S3, angka1);
        }
    }
    else if (Top(S1) == Top(S2)) // jika panjang s1 sama dengan s2
    {
        int k = 0;
        while (k <= Top(S1) && (negatif == false))
        {
            if (S1.T[k] < S2.T[k])
            {
                negatif = true;
            }
            k++;
        }

        if (negatif == false) // s1 lebih besar dari s2
        {
            while (!IsEmpty(S2))
            {
                Pop(&S1, &angka1);
                Pop(&S2, &angka2);
                if (angka1 < angka2)
                {
                    angka1 += 10;
                    InfoTop(S1) -= 1;
                }
                hitung = angka1 - angka2;
                Push(&S3, hitung);
            }
        }
        else // s1 lebih kecil dari s2
        {
            while (!IsEmpty(S2))
            {
                Pop(&S1, &angka1);
                Pop(&S2, &angka2);
                if (angka2 < angka1)
                {
                    angka2 += 10;
                    InfoTop(S2) -= 1;
                }
                hitung = angka2 - angka1;
                Push(&S3, hitung);
            }
        }
    }
    else // s1 lebih kecil dari s1
    {
        negatif = true;
        while (!IsEmpty(S1))
        {
            Pop(&S1, &angka1);
            Pop(&S2, &angka2);
            if (angka2 < angka1)
            {
                angka2 += 10;
                InfoTop(S2) -= 1;
            }
            hitung = angka2 - angka1;
            Push(&S3, hitung);
        }

        while (!IsEmpty(S2))
        {
            Pop(&S2, &angka2);
            Push(&S3, angka2);
        }
    }

    int j = Top(S3);
    int leadingzeros = 0;
    while (S3.T[j] == 0)
    {
        j--;
        leadingzeros++;
    }

    if (leadingzeros == Top(S3) + 1) // hasil pengurangan = 0
    {
        printf("0");
    }
    else
    {
        if (negatif == true)
        {
            printf("-");
        }
        for (int i = Top(S3) - leadingzeros; i >= 0; i--)
        {
            printf("%d", S3.T[i]);
        }
    }
    printf("\n");
    return 0;
}
