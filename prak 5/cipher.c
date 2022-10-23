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
            if (currentWord.TabWord[i] + x > 90)
            {
                printf("%c", 65 + ((currentWord.TabWord[i] + x) % 91));
            }
            else
            {
                printf("%c", currentWord.TabWord[i] + x);
            }
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
