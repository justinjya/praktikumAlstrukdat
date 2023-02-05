#include <stdio.h>
#include "mesinkarakter.h"

int hitungkarakter (char karakter)
{
    int count = 0;
    START();
    while (GetCC() != MARK)
    {
        if (GetCC() == karakter)
        {
            count++;
        }
        ADV();
    }
    return count;
}