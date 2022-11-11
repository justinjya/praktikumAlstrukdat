#include "union_map.h"

Map UnionMap(Map m1, Map m2, boolean key_based)
{
    Map m3;
    CreateEmpty(&m3);
    int i = 0;
    int j = 0;
    while (i < m1.Count)
    {
        Insert(&m3, m1.Elements[i].Key, m1.Elements[i].Value);
        i++;
    }
    while (j < m2.Count)
    {
        Insert(&m3, m2.Elements[j].Key, m2.Elements[j].Value);
        j++;
    }
    infotype temp;
    if (key_based == true)
    {
        for (int i = 0; i < m3.Count - 1; i++)
        {
            for (int j = 0; j < m3.Count - 1; j++)
            {
                if (m3.Elements[j].Key > m3.Elements[j + 1].Key)
                {
                    temp = m3.Elements[j];
                    m3.Elements[j] = m3.Elements[j + 1];
                    m3.Elements[j + 1] = temp;
                }
            }
        }
    }
    else
    {
        for (int i = 0; i < m3.Count - 1; i++)
        {
            for (int j = 0; j < m3.Count - 1; j++)
            {
                if (m3.Elements[j].Value > m3.Elements[j + 1].Value)
                {
                    temp = m3.Elements[j];
                    m3.Elements[j] = m3.Elements[j + 1];
                    m3.Elements[j + 1] = temp;
                }
            }
        }
    }
    return m3;
}

