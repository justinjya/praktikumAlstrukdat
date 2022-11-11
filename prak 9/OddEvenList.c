#include "OddEvenList.h"
#include "listlinier.h"

void OddEvenList(List L, List *Odd, List *Even)
{
    CreateEmpty(Odd);
    CreateEmpty(Even);

    address P;
    P = First(L);

    while (P != Nil)
    {
        if (Info(P) % 2 == 0 || Info(P) == 0)
        {
            if (IsEmpty(*Even))
            {
                InsVFirst(Even, Info(P));
            }
            else
            {
                if (Info(P) >= Max(*Even))
                {
                    InsVLast(Even, Info(P));
                }
                else
                {
                    InsVFirst(Even, Info(P));
                }
            }
        }
        else
        {
            if (IsEmpty(*Odd))
            {
                InsVFirst(Odd, Info(P));
            }
            else
            {
                if (Info(P) >= Max(*Odd))
                {
                    InsVLast(Odd, Info(P));
                }
                else
                {
                    InsVFirst(Odd, Info(P));
                }
            }    
        }
        P = Next(P);
    }
}