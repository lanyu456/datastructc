#ifndef __LINEAR_LIST_H__
#define __LINEAR_LIST_H__

#include <stdbool.h>

// --------------SequenceList definition--------------
#define InitSize 10
typedef struct
{
    int *data;
    int max_size;
    int length;
} SequenceList;

bool InitSequenceList(SequenceList *list);

void ReallocList(SequenceList *list, int delta);

void ShowSequenceList(SequenceList *list, char separator);

bool ListInsert(SequenceList *list, int index, int value);

void sq_push(SequenceList *list, int value);

bool ListDelete(SequenceList *list, int index, int *removed);

int sq_pop(SequenceList *list);

inline int GetElem(SequenceList *list, int index) { return index > 0 && index < list->length ? list->data[index] : -1; }

int LocateElem(SequenceList *list, int target);

void FreeSequenceList(SequenceList *list);

// --------------LinkedList definition--------------
typedef struct NodeStruct
{
    int data;
    struct NodeStruct *next;
} Node, *LinkedList;

bool InitLinkedList(LinkedList list);

bool LinkedListInsert(LinkedList list, int pos, int data);

#endif // __LINEAR_LIST_H__