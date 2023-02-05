#include <stdio.h>
#include "boolean.h"
#include "mesinkarakterv2.h"
#include "mesinkata.h"


int main()
{
    int x;
    STARTWORD();
    x = currentWord.Length;
    while (!isEndWord())
    {
        for (int i = 0; i < currentWord.Length; i++)
        {
            printf("%c", 65 + (((currentWord.TabWord[i] - 65) + x) % 26));
        }
        if (currentChar != MARK)
        {
            printf(" ");
        }
        ADVWORD();
    }
    printf(".\n");
    return 0;
}
