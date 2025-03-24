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

void InitSequenceList(SequenceList *L);

void ReallocList(SequenceList *L, int len);

void ShowSequenceList(SequenceList *L, char sep);

bool ListInsert(SequenceList *L, int index, int value);

void sq_push(SequenceList *L, int value);

bool ListDelete(SequenceList *L, int index, int *result);

int sq_pop(SequenceList *L);

inline int GetElem(SequenceList *L, int index) { return index > 0 && index < L->length ? L->data[index] : -1; }

int LocateElem(SequenceList *L, int target);

// --------------LinkedList definition--------------
typedef struct
{
    int data;
    Node *next;
} Node, *LinkedList;

void InitLinkedList(LinkedList L);

#endif // __LINEAR_LIST_H__