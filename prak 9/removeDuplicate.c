#include <stdio.h>
#include "removeDuplicate.h"

List removeDuplicate(List L)
{
    List removedDuplicate;
    CreateEmpty(&removedDuplicate);
    
    address P;
    P = First(L);
    while (P != Nil)
    {
        if (Search(removedDuplicate, Info(P)) == Nil)
        {
            InsVLast(&removedDuplicate, Info(P));
        }
        P = Next(P);
    }
    return removedDuplicate;
}