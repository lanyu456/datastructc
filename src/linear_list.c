#include "linear_list.h"
#include <stdio.h>
#include <stdlib.h>

// --------------SequenceList definition--------------
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
        for (int i = L->length; i < L->max_size; ++i)
            L->data[i] = 0;
    }
    else
    {
        perror("Realloc Error:");
        free(L->data);
        exit(EXIT_FAILURE);
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
    printf("\n");
}

bool ListInsert(SequenceList *L, int index, int value)
{
    if (index < 0 && index > L->length)
        return false;
    if (L->length >= L->max_size)
        ReallocList(L, L->length);

    for (int i = L->length; i > index; --i)
        L->data[i] = L->data[i - 1];
    L->data[index] = value;
    L->length++;

    return true;
}

void sq_push(SequenceList *L, int value)
{
    if (L->length >= L->max_size)
        ReallocList(L, L->length);
    L->data[L->length] = value;
    L->length++;
}

bool ListDelete(SequenceList *L, int index, int *result)
{
    if (index < 0 && index >= L->length)
        return false;
    *result = L->data[index];
    for (int i = index; i < L->length - 1; ++i)
        L->data[i] = L->data[i + 1];
    L->data[L->length - 1] = 0;
    L->length--;

    return true;
}

int sq_pop(SequenceList *L)
{
    if (L->length == 0)
        return -1;
    int ret = L->data[L->length - 1];
    L->data[L->length - 1] = 0;
    L->length--;
    return ret;
}

int LocateElem(SequenceList *L, int target)
{
    int index = -1;
    for (int i = 0; i < L->length; ++i)
        if (L->data[i] == target)
        {
            index = i;
            break;
        }
    return index;
}

// --------------LinkedList definition--------------
