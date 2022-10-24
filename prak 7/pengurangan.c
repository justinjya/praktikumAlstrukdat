#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main()
{
    Stack S1;
    Stack S2;
    char *s1;
    char *s2;
    long long int angka1 = 0;
    long long int angka2 = 0;
    long long int satuan;
    long long int hasil;
    infotype val;
    CreateEmpty(&S1);
    CreateEmpty(&S2);
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

    satuan = 1;
    while (!IsEmpty(S1))
    {
        Pop(&S1, &val);
        angka1 += val * satuan;
        satuan = satuan * 10;
    }
    satuan = 1;
    while (!IsEmpty(S2))
    {
        Pop(&S2, &val);
        angka2 += val * satuan;
        satuan = satuan * 10;
    }
    hasil = angka1 - angka2;
    printf("%lld\n", hasil);
    return 0;
}