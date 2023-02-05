#include <stdio.h>
#include "stack.c"
#include "aritmatika.c"

void display(Stack S)
{
    for (int i = 0; i <= Top(S); i++)
    {
        printf("%d", S.T[i]);
    }
    printf("\n");
    // printf("IsEmpty = %d\n", IsEmpty(S));
    // printf("idxTop = %d\n", Top(S));
    // printf("IsFull = %d\n", IsFull(S));
}

// tes palindrom
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

//tes aritmatika
// int main()
// {
//     // Stack S;
//     // infotype angka1;
//     // infotype angka2;
//     // infotype eval;
//     // char *input = "223+*";
//     // int hasil;
//     // CreateEmpty(&S);

//     // while (*input != '\0')
//     // {
//     //     if (!isOperator(*input))
//     //     {
//     //         Push(&S, (*input - 48));
//     //     }
//     //     else
//     //     {
//     //         Pop(&S, &angka2);
//     //         Pop(&S, &angka1);
//     //         hasil = hitung(angka1, angka2, *input);
//     //         Push(&S, hasil);
//     //     }
//     //     input++;
//     // }
//     // Pop(&S, &eval);
//     // printf("%d\n", eval);
//     printf("%d", eval("23+", 1));
// }