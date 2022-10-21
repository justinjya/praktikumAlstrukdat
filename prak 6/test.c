#include <stdio.h>
#include "queue.c"
// #include "tanpaBomb.c"
// #include "copyqueue.c"

// test tanpaBomb
// int main()
// {
//     Queue Q;
//     ElType val;
//     CreateQueue(&Q);
//     enqueue(&Q, 2);
//     enqueue(&Q, 3);
//     enqueue(&Q, 4);
//     enqueue(&Q, 5);
//     enqueue(&Q, 6);
//     printf("Queue:\n");
//     displayQueue(Q);
//     printf("Tanpa Bomb:\n");
//     Q = tanpaBomb(Q, 6);
//     displayQueue(Q);
// }

//test copyqueue
// int main()
// {
//     Queue Q;
//     Queue Copy;
//     ElType val;
//     CreateQueue(&Q);
//     CreateQueue(&Copy);
//     enqueue(&Q, 2);
//     enqueue(&Q, 3);
//     enqueue(&Q, 4);
//     enqueue(&Q, 5);
//     enqueue(&Q, 6);
//     dequeue(&Q, &val);
//     printf("Before\n");
//     printf("Queue:\n");
//     displayQueue(Q);
//     printf("Head = %d\nTail = %d\n", HEAD(Q), TAIL(Q));
//     printf("Copy Queue:\n");
//     displayQueue(Copy);
//     printf("Head = %d\nTail = %d\n", HEAD(Copy), TAIL(Copy));
//     copyQueue(&Q, &Copy);
//     printf("After\n");
//     printf("Original Queue:\n");
//     displayQueue(Q);
//     printf("Head = %d\nTail = %d\n", HEAD(Q), TAIL(Q));
//     printf("Copy Queue:\n");
//     displayQueue(Copy);
//     printf("Head = %d\nTail = %d\n", HEAD(Copy), TAIL(Copy));
// }

//test restoran
// ElType min(Queue q)
// {
//     if (isEmpty(q))
//     {
//         return 0;
//     }
//     else
//     {
//         ElType min = HEAD(q);
//         ElType val;
//         for (int i = IDX_HEAD(q); i <= IDX_TAIL(q); i++)
//         {
//             dequeue(&q, &val);
//             if (min > val)
//             {
//                 min = val;
//             }
//             enqueue(&q, val);
//         }
//         return min;
//     }
// }

// ElType max(Queue q)
// {
//     if (isEmpty(q))
//     {
//         return 0;
//     }
//     else
//     {
//         ElType max = HEAD(q);
//         ElType val;
//         for (int i = IDX_HEAD(q); i <= IDX_TAIL(q); i++)
//         {
//             dequeue(&q, &val);
//             if (max < val)
//             {
//                 max = val;
//             }
//             enqueue(&q, val);
//         }
//         return max;
//     }
// }

// int main()
// {
//     int masukan;
//     int waktu;
//     Queue Q;
//     Queue tersaji;
//     ElType val;
//     CreateQueue(&Q);
//     CreateQueue(&tersaji);
//     masukan = 3;
//     while (masukan > 0)
//     {
//         scanf("%d", &masukan);
//         if (masukan == 1)
//         {
//             scanf("%d", &waktu);
//             if (waktu > 0)
//             {
//                 enqueue(&Q, waktu);
//             }
//         }
//         else if (masukan == 2)
//         {
//             if (isEmpty(Q) == 0)
//             {
//                 dequeue(&Q, &val);
//                 enqueue(&tersaji, val);
//             }
//         }
//     }
//     printf("Queue Waktu Masakan:\n");
//     displayQueue(Q);
//     printf("Tersaji:\n");
//     displayQueue(tersaji);
//     printf("Saji = %d\n", length(tersaji));
//     printf("Min = %d\n", min(tersaji));
//     printf("Max = %d\n", max(tersaji));
//     return 0;
// }