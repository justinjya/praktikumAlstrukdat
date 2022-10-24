#include <stdio.h>
#include "valid.h"

Stack validParantheses(char *input, int length)
{
    Stack S;
    CreateEmpty(&S);
    infotype val;
    while (*input != '\0')
    {
        if ((*input == '(') && (*(input + 1) == ')'))
        {
            Push(&S, *(input));
            Push(&S, *(input + 1));
        }
        else if ((*input == '[') && (*(input + 1) == ']'))
        {
            Push(&S, *(input));
            Push(&S, *(input + 1));
        }
        else if ((*input == '{') && (*(input + 1) == '}'))
        {
            Push(&S, *(input));
            Push(&S, *(input + 1));
        }
        input++;
    }
    return S;
}
