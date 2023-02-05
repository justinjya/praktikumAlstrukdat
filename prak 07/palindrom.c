#include <stdio.h>
#include "stack.h"

int main()
{
    Stack S;
    infotype X;
    CreateEmpty(&S);

    infotype x;
    x = 1;
    while (x > 0)
    {
        scanf("%d", &x);
        if (x > 0)
        {
            Push(&S, x);
        }
    }

    Stack Copy;
    Stack temp;
    infotype top;
    CreateEmpty(&Copy);
    CreateEmpty(&temp);
    while (!IsEmpty(S))
    {
        top = InfoTop(S);
        Push(&Copy, top);
        Push(&temp, top);
        Pop(&S, &X);
    }
    while (!IsEmpty(temp))
    {
        Pop(&temp, &X);
        Push(&S, X);
    }

    int count = 0;
    for (int i = 0; i <= Top(S); i++)
    {
        if (S.T[i] == Copy.T[i])
        {
            count++;
        }
    }
    if (IsEmpty(S))
    {
        printf("Stack kosong\n");
    }
    else
    {
        if (count == Top(S) + 1)
        {
            printf("Palindrom\n");
        }
        else
        {
            printf("Bukan Palindrom\n");
        }
    }
    return 0;
}