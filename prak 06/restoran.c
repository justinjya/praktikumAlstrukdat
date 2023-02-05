#include <stdio.h>
#include "queue.h"

ElType min(Queue q)
{
    if (isEmpty(q))
    {
        return 0;
    }
    else
    {
        ElType min = HEAD(q);
        ElType val;
        for (int i = IDX_HEAD(q); i <= IDX_TAIL(q); i++)
        {
            dequeue(&q, &val);
            if (min > val)
            {
                min = val;
            }
            enqueue(&q, val);
        }
        return min;
    }
}

ElType max(Queue q)
{
    if (isEmpty(q))
    {
        return 0;
    }
    else
    {
        ElType max = HEAD(q);
        ElType val;
        for (int i = IDX_HEAD(q); i <= IDX_TAIL(q); i++)
        {
            dequeue(&q, &val);
            if (max < val)
            {
                max = val;
            }
            enqueue(&q, val);
        }
        return max;
    }
}

int main()
{
    int masukan;
    int waktu;
    Queue Q;
    Queue tersaji;
    ElType val;
    CreateQueue(&Q);
    CreateQueue(&tersaji);
    masukan = 3;
    while (masukan > 0)
    {
        scanf("%d", &masukan);
        if (masukan == 1)
        {
            scanf("%d", &waktu);
            if (waktu > 0)
            {
                enqueue(&Q, waktu);
            }
        }
        else if (masukan == 2)
        {
            if (isEmpty(Q) == 0)
            {
                dequeue(&Q, &val);
                enqueue(&tersaji, val);
            }
        }
    }
    printf("%d\n", length(tersaji));
    printf("%d\n", min(tersaji));
    printf("%d\n", max(tersaji));
    return 0;
}