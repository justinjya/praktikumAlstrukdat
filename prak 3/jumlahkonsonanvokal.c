#include <stdio.h>
#include "jumlahkonsonanvokal.h"

int isVowel(char *ch)
{
    if ((*ch == 'a') || (*ch == 'i') || (*ch == 'u') || (*ch == 'e') || (*ch == 'o') || (*ch == 'A') || (*ch == 'I') || (*ch == 'U') || (*ch == 'E') || (*ch == 'O'))
        {
            return 1; 
        }
}

int isAlphabet(char *ch)
{
    if ((*ch >= 97 && *ch <= 122) || (*ch >=65 && *ch <= 90))
    {
        if ((*ch != 'a') && (*ch != 'i') && (*ch != 'u') && (*ch != 'e') && (*ch != 'o') && (*ch != 'A') && (*ch != 'I') && (*ch != 'U') && (*ch != 'E') && (*ch != 'O'))
        {
            return 1;
        }
    }
}

void jumlahKonsonanVokal(char *ch, int *kons, int *vow)
{
    while (*ch != '\0')
    {
        if (isVowel(ch) == 1)
        {
            (*vow)++;
        }
        else if (isAlphabet(ch) == 1)
        {
            (*kons)++;
        }
        ch++;
    }
}