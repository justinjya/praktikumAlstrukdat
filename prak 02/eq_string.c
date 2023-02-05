#include <stdio.h>
#include <string.h>

int main()
{
    char str1[100], str2[100];
    scanf("%s %s", &str1, &str2);
    int i, j, k, count, len1, len2;
    len1 = strlen(str1);
    len2 = strlen(str2);
    count = 0;
    if (len1 == len2)
    {
        for (i = 0; i < len1; i++)
        {
            if (str1[i] < 97)
            {
                str1[i] = str1[i] + 32;
            }
            if (str2[i] < 97)
            {
                str2[i] = str2[i] + 32;
            }
            if (str1[i] == str2[i])
            {
                count += 1;
            }
        }
        if (count == len1)
        {
            printf("Ya\n");
        }
        else
        {
            printf("Tidak\n");
        }
    }
    else
    {
        printf("Tidak\n");
    }
    return 0;
}