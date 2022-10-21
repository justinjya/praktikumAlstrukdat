#include <stdio.h>
#include "copyqueue.h"

void copyQueue(Queue *queueInput, Queue *queueOutput)
{
    Queue temp;
    ElType val;
    CreateQueue(&temp);
    while (isEmpty(*queueInput) == 0)
    {
        dequeue(queueInput, &val);
        enqueue(&temp, val);
        enqueue(queueOutput, val);
    }
    while (isEmpty(temp) == 0)
    {
        dequeue(&temp, &val);
        enqueue(queueInput, val);
    }
}