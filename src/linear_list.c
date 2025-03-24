#include "linear_list.h"
#include <stdio.h>
#include <stdlib.h>

void InitSequenceList(SequenceList *L)
{
    if (L == NULL)
        return;
    L->data = (int *)calloc(InitSize, sizeof(int));
    L->max_size = InitSize;
    L->length = 0;
}

void ReallocList(SequenceList *L, int len)
{
    int *temp = realloc(L->data, (L->max_size + len) * sizeof(int));
    if (temp != NULL)
    {
        L->data = temp;
        L->max_size += len;
    }
    else
    {
        printf("内存不够，顺序表扩容失败。");
    }
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
