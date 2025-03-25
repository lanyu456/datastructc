#ifndef __LINEAR_LIST_H__
#define __LINEAR_LIST_H__

#include <stdbool.h>
#include <stdlib.h>

// --------------SequenceList definition--------------
#define InitSize 10
typedef struct
{
    int *data;
    int max_size;
    int length;
} SequenceList, Stack;

bool InitSequenceList(SequenceList *list);

bool SeqEmpty(SequenceList *list);

void ReallocSequenceList(SequenceList *list, int delta);

void ShowSequenceList(SequenceList *list, char separator);

bool SequenceListInsertAt(SequenceList *list, int index, int value);

bool SequencePush(SequenceList *list, int value);

bool SequenceListDeleteAt(SequenceList *list, int index, int *removed);

int SequencePop(SequenceList *list);

int SeqGetAt(SequenceList *list, int index);

int SeqLocate(SequenceList *list, int target);

void FreeSequenceList(SequenceList *list);

// --------------LinkedList definition--------------
typedef struct NodeStruct
{
    int data;
    struct NodeStruct *next;
} Node, *LinkedList;

LinkedList InitLinkedList();

void ShowLinkedList(LinkedList list);

bool LinkedListInsertAt(LinkedList list, int pos, int data);

Node *InsertAfterNode(Node *node, int data);

Node *InsertBeforeNode(Node *node, int data);

bool LinkedListDeleteAt(LinkedList list, int pos, int *removed);

Node *LinkGetAt(LinkedList list, int pos);

Node *LinkLocate(LinkedList list, int target);

int LinkLength(LinkedList list);

bool ReverseLinkedList(LinkedList list);

bool LinkedListInsertHead(LinkedList list);

bool LinkedListInsertTail(LinkedList list);

void FreeLinkedList(LinkedList list);

// --------------Double linkedList definition--------------
typedef struct DNodeStruct
{
    int data;
    struct DNodeStruct *prev, *next;
} DNode, *DLinkedList;

DLinkedList InitDLinkedList();

bool DLLEmpty(DLinkedList dlist);

DNode *InsertAfterDNode(DNode *node, int data);

DNode *InsertBeforeDNode(DNode *node, int data);

bool DeleteNextDNode(DLinkedList dlist);

void FreeDLinkedList(DLinkedList dlist);

// --------------Circle linkedList definition--------------
typedef struct CNodeStruct
{
    int data;
    struct CNodeStruct *next;
} CNode, *CLinkedList;

CLinkedList InitCLinkedList();

void FreeCLinkedList(CLinkedList clist);

bool CLLEmpty(CLinkedList clist);

bool isTail(CLinkedList clist, CNode *cnode);

#endif // __LINEAR_LIST_H__P