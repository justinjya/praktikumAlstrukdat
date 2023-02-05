#include <stdio.h>
#include "hitungfrekuensi.h"

int hitungfrekuensi()
{
    int count = 0;
    START();
    while (currentChar != MARK) 
    {
        if ((currentChar == 't') || (currentChar == 'T'))
        {
            ADV();
            if ((currentChar == 'i') || (currentChar == 'I'))
            {
                ADV();
                if ((currentChar == 'g') || (currentChar == 'G'))
                {
                    ADV();
                    if ((currentChar == 'a') || (currentChar == 'A'))
                    {
                        count++;
                    }
                }
            }
        }
        ADV();
    }
    return count;
}