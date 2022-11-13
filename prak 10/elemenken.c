#include <stdio.h>
#include "listsirkuler.h"

int ElemenKeN(List L, int r) {
  address P;
  int count;
  count = 0;
  P = First(L);
  while (count < r)
  {
    P = Next(P);
    count++;
  }
  return Info(P);
}

int main () {
  List L;
  int r, n;
  CreateEmpty(&L);
  n = -1;
  while (n != 0)
  {
    scanf("%d", &n);
    if (n > 0)
    {
        InsVLast(&L, n);
    }
  }
  scanf("%d", &r);
  if (IsEmpty(L))
  {
    printf("List Kosong\n");
  }
  else
  {
    printf("%d\n", ElemenKeN(L, r));
  }
  return 0;
}
