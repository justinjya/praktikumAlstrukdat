#include <stdio.h>
#include "tanpaBomb.h"

Queue tanpaBomb(Queue queue, ElType bomb)
{
    Queue output;
    ElType val;
    CreateQueue(&output);
    while (isEmpty(queue) == 0)
    {
        if (HEAD(queue) == bomb)
        {
            dequeue(&queue, &val);
        }
        else
        {
            dequeue(&queue, &val);
            enqueue(&output, val);
        }
    }
    return output;
}