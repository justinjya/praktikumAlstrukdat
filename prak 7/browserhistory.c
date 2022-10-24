#include <stdio.h>
#include "browserhistory.h"

void browserHistoryVisit(Stack *openedTab, Stack *history, char *url)
{
    if (!IsFull(*openedTab))
    {
        Push(openedTab, url);
    }
}

char *currentUrl(Stack *openedTab)
{
    return InfoTop(*openedTab);
}

char *browserHistoryBack(Stack *openedTab, Stack *history, int steps)
{
    infotype val;
    for (int i = 0; i < steps; i++)
    {
        Pop(openedTab, &val);
        Push(history, val);
    }
    return InfoTop(*openedTab);
}

char *browserHistoryForward(Stack *openedTab, Stack *history, int steps)
{
    infotype val;
    for (int i = 0; i < steps; i++)
    {
        Pop(history, &val);
        Push(openedTab, val);
    }
    return InfoTop(*openedTab);
}

void browserHistoryFree(Stack *history)
{
    infotype val;
    while (!IsEmpty(*history))
    {
        Pop(history, &val);
    }
}