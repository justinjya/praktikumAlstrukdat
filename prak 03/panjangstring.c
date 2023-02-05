#include <stdio.h>
#include "panjangstring.h"

int panjangString(char *ch)
{
    int len = 0;
    while (*ch != '\0')
    {
        len++;
        ch++;
    }
    return len;
}