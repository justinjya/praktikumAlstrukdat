#include <stdio.h>
#include "reverse.h"

void transferReverse(Queue *q1, Queue *q2)
{
    int i = 0;
    int length;
    length = Length(*q1);
    while (i < length)
    {
        int count;
        int j = 1;
        count = Length(*q1);
        while (j < count)
        {
            Push(q1, Pop(q1));
            j++;
        }
        Push(q2, Pop(q1));
        i++;
    }
}