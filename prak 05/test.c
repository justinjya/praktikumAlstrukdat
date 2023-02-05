#include <stdio.h>

int main()
{
    int x;
    char *currentWord = "XYZ";
    int currentWordLength = 4;
    x = 1;
    // while (*currentWord != '\0')
    // {
        for (int i = 0; i < currentWordLength - 1; i++)
        {
            if (currentWord[i] + x > 90)
            {
                printf("%c", 65 + ((currentWord[i] + x) % 91));
            }
            else
            {
                printf("%c", currentWord[i] + x);
            }
        }
        // for (int i = 0; i < currentWordLength; i++)
        // {
        //     printf("%c", currentWord[i]);
        // }
        // printf(" ");
    // }
    printf("\n");
    return 0;
}