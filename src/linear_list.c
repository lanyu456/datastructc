#include "linear_list.h"
#include <stdio.h>
#include <stdlib.h>

// --------------SequenceList definition--------------
bool InitSequenceList(SequenceList *list)
{
    if (list == NULL)
        return false;
    list->data = (int *)calloc(InitSize, sizeof(int));
    list->max_size = InitSize;
    list->length = 0;
    return true;
}

void ReallocList(SequenceList *list, int delta)
{
    int *temp = realloc(list->data, (list->max_size + delta) * sizeof(int));
    if (temp != NULL)
    {
        list->data = temp;
        list->max_size += delta;
        for (int i = list->length; i < list->max_size; ++i)
            list->data[i] = 0;
    }
    else
    {
        perror("Realloc Error:");
        free(list->data);
        exit(EXIT_FAILURE);
    }
}

void ShowSequenceList(SequenceList *list, char separator)
{
    if (list == NULL)
        return;
    if (list->length > 0)
    {
        printf("%d", list->data[0]);
        for (int i = 1; i < list->length; ++i)
            printf("%c%d", separator, list->data[i]);
    }
    printf("\n");
}

bool ListInsert(SequenceList *list, int index, int value)
{
    if (index < 0 && index > list->length)
        return false;
    if (list->length >= list->max_size)
        ReallocList(list, list->length);

    for (int i = list->length; i > index; --i)
        list->data[i] = list->data[i - 1];
    list->data[index] = value;
    list->length++;

    return true;
}

void sq_push(SequenceList *list, int value)
{
    if (list->length >= list->max_size)
        ReallocList(list, list->length);
    list->data[list->length] = value;
    list->length++;
}

bool ListDelete(SequenceList *list, int index, int *removed)
{
    if (index < 0 && index >= list->length)
        return false;
    *removed = list->data[index];
    for (int i = index; i < list->length - 1; ++i)
        list->data[i] = list->data[i + 1];
    list->data[list->length - 1] = 0;
    list->length--;

    return true;
}

int sq_pop(SequenceList *list)
{
    if (list->length == 0)
        return -1;
    int ret = list->data[list->length - 1];
    list->data[list->length - 1] = 0;
    list->length--;
    return ret;
}

int LocateElem(SequenceList *list, int target)
{
    int index = -1;
    for (int i = 0; i < list->length; ++i)
        if (list->data[i] == target)
        {
            index = i;
            break;
        }
    return index;
}

void FreeSequenceList(SequenceList *list)
{
    if (list != NULL)
    {
        free(list->data);
        list->data = NULL;
    }
}

// --------------LinkedList definition--------------
bool InitLinkedList(LinkedList list)
{
    // The linkedlist with head node
    list = (LinkedList)malloc(sizeof(Node));
    if (list == NULL)
        return false;
    list->data = 0;
    list->next = NULL;
    return true;
}

bool LinkedListInsert(LinkedList list, int pos, int data) {}
