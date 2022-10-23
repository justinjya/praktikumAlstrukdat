#include <stdio.h>
#include "anagramalstrukdat.h"

int stringLength(char *string)
{
    int length = 0;
    while (*string != '\0')
    {
        length++;
        string++;
    }
    return length;
}

Word toKata(char *command)
{
    Word Kata;
    int i = 0;
    while (*command != '\0')
    {
        Kata.TabWord[i] = *command;
        i++;
        command++;
    }
    Kata.Length = i;
    return Kata;
}

boolean isAnagram(Word string1, Word string2)
{
    if (string1.Length == string2.Length)
    {
        int count = 0;
        for (int i = 0; i < string1.Length; i++)
        {
            for (int j = 0; j < string1.Length; j++)
            {
                if (string1.TabWord[j] > string1.TabWord[j + 1])
                {
                    char temp;
                    temp = string1.TabWord[j + 1];
                    string1.TabWord[j + 1] = string1.TabWord[j];
                    string1.TabWord[j] = temp;
                }
                if (string2.TabWord[j] > string2.TabWord[j + 1])
                {
                    char temp;
                    temp = string2.TabWord[j + 1];
                    string2.TabWord[j + 1] = string2.TabWord[j];
                    string2.TabWord[j] = temp;
                }
            }
        }
        for (int i = 0; i < string1.Length; i++)
        {
            if (string1.TabWord[i] == string2.TabWord[i])
            {
                count++;
            }
        }
        if (count == string1.Length)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

void anagramalstrukdat(int *frek)
{
    Word alstrukdat;
    *frek = 0;
    alstrukdat = toKata("alstrukdat");
    STARTWORD();
    while (!isEndWord())
    {
        if (isAnagram(alstrukdat, currentWord))
        {
            (*frek)++;
        }
        ADVWORD();
    }
}
