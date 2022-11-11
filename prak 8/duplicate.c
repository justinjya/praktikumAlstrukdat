#include "duplicate.h"

Set arrToSet(int *arr, int arrSize)
{
    Set S;
    CreateEmpty(&S);
    for (int i = 0; i < arrSize; i++)
    {
        Insert(&S, arr[i]);
    }
    return S;
}

void removeDuplicateDesc(int *arr, int arrSize, int *arrRes, int *arrResSize)
{
    Set S;
    CreateEmpty(&S);
    *arrResSize = 0;
    S = arrToSet(arr, arrSize);
    address i = 0;
    while (i < S.Count)
    {
        arrRes[i] = S.Elements[i];
        i++;
        (*arrResSize)++;
    }

    infotype temp;
    for (address k = 0; k < *arrResSize; k++)
    {
        for (address l = 0; l < *arrResSize; l++)
        {
            if (arrRes[k] > arrRes[l])
            {
                temp = arrRes[k];
                arrRes[k] = arrRes[l];
                arrRes[l] = temp;
            }
        }
    }
}