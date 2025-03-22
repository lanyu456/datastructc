#include "linear_list.h"
#include <stdio.h>

void InitSequenceList(SequenceList *L)
{
    if (L == NULL)
        return;
    for (int i = 0; i < MaxSize; ++i)
        L->data[i] = 0;
    L->length = 0;
}

void ShowSequenceList(SequenceList *L, char sep)
{
    if (L == NULL)
        return;
    if (L->length > 0)
    {
        printf("%d", L->data[0]);
        for (int i = 1; i < L->length; ++i)
            printf("%c%d", sep, L->data[i]);
    }
}
