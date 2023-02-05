#include <stdio.h>
#include "listlinier.h"

int main() {
    List fibonacci;
    CreateEmpty(&fibonacci);

    infotype el;
    scanf("%d", &el);

    if (el == 0) {
        PrintInfo(fibonacci);
        return 0;
    } else if (el == 1) {
        infotype firstEl;
        scanf("%d", &firstEl);
        InsVLast(&fibonacci, firstEl);
        PrintInfo(fibonacci);
    } else {
        infotype firstEl, secondEl;
        scanf("%d", &firstEl);
        scanf("%d", &secondEl);

        infotype angka;

        InsVLast(&fibonacci, firstEl);
        InsVLast(&fibonacci, secondEl);

        for (infotype i = 0; i < el - 2; i++)
        {
            address Before, Last;
            Last = First(fibonacci);
            while (Next(Last) != Nil)
            {
                Last = Next(Last);
            }
            Before = First(fibonacci);
            while (Next(Before) != Last)
            {
                Before = Next(Before);
            }
            angka = Info(Last) + Info(Before);
            InsVLast(&fibonacci, angka);
        }
        PrintInfo(fibonacci);
        }
    return 0;
}