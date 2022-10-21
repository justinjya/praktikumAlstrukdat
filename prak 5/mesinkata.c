#include <stdio.h>
#include "mesinkata.h"
#include "mesinkarakterv2.h"

boolean EndWord;
Word currentWord;

void IgnoreBlanks()
{
    while (currentChar == ' ')
    {
        ADV();
    }
}

void STARTWORD()
{
    START();
    IgnoreBlanks();
    if (currentChar == '.')
    {
        EndWord = true;
    }
    else
    {
        EndWord = false;
        CopyWord();
    }
}

void ADVWORD()
{
    IgnoreBlanks();
    if (currentChar == '.')
    {
        EndWord = true;
    }
    else
    {
        CopyWord();
        IgnoreBlanks();
    }
}

void CopyWord()
{
    int i = 0;
    while ((currentChar != '.') && (currentChar != BLANK))
    {
        currentWord.TabWord[i] = currentChar;
        ADV();
        i++;
    }
    if (i > NMax)
    {
        currentWord.Length = NMax;
    }
    else
    {
        currentWord.Length = i;
    }
}