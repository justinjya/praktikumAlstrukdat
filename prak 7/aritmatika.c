#include <stdio.h>
#include "aritmatika.h"

boolean isOperator(char input)
{
    if ((input == '+') || (input == '-') || (input == '*') || (input == '/'))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int hitung(int angka1, int angka2, char op)
{
    if (op == '+')
    {
        return angka1 + angka2;
    }
    else if (op == '-')
    {
        return angka1 - angka2;
    }
    else if (op == '*')
    {
        return angka1 * angka2;
    }
    else if (op == '/')
    {
        return angka1 / angka2;
    }
}

int eval(char *input, int length)
{
    Stack S;
    infotype angka1;
    infotype angka2;
    infotype eval;
    int hasil;
    CreateEmpty(&S);
    while (*input != '\0')
    {
        if (!isOperator(*input))
        {
            Push(&S, (*input - 48));
        }
        else
        {
            Pop(&S, &angka2);
            Pop(&S, &angka1);
            hasil = hitung(angka1, angka2, *input);
            Push(&S, hasil);
        }
        input++;
    }
    Pop(&S, &eval);
    return eval;
}
