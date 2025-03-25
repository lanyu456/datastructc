#include "linear_list.h"
#include <stdio.h>

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

inline bool SeqEmpty(SequenceList *list) { return list->length == 0; }

void ReallocSequenceList(SequenceList *list, int delta)
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

bool SequenceListInsertAt(SequenceList *list, int index, int value)
{
    if (index < 0 && index > list->length)
        return false;
    if (list->length >= list->max_size)
        ReallocSequenceList(list, list->length);

    for (int i = list->length; i > index; --i)
        list->data[i] = list->data[i - 1];
    list->data[index] = value;
    list->length++;

    return true;
}

bool SequencePush(SequenceList *list, int value)
{
    if (list == NULL)
        return false;
    if (list->length >= list->max_size)
        ReallocSequenceList(list, list->length);
    list->data[list->length] = value;
    list->length++;
    return true;
}

bool SequenceListDeleteAt(SequenceList *list, int index, int *removed)
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

int SequencePop(SequenceList *list)
{
    if (list->length == 0)
        return -1;
    int ret = list->data[list->length - 1];
    list->data[list->length - 1] = 0;
    list->length--;
    return ret;
}

int SeqGetAt(SequenceList *list, int index) { return index > 0 && index < list->length ? list->data[index] : -1; }

int SeqLocate(SequenceList *list, int target)
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
LinkedList InitLinkedList()
{
    // The linkedlist with head node
    LinkedList list = (LinkedList)malloc(sizeof(Node));
    if (list == NULL)
        return NULL;
    list->data = 0;
    list->next = NULL;
    return list;
}

void ShowLinkedList(LinkedList list)
{
    Node *head = list;
    while (head->next != NULL)
    {
        head = head->next;
        printf("%d ", head->data);
    }
    printf("\n");
}

bool LinkedListInsertAt(LinkedList list, int pos, int data) { return InsertAfterNode(LinkGetAt(list, pos), data); }

Node *InsertAfterNode(Node *node, int data)
{
    if (node == NULL)
        return NULL;
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
        return NULL;
    newNode->data = data;
    newNode->next = node->next;
    node->next = newNode;
    return newNode;
}

Node *InsertBeforeNode(Node *node, int data)
{
    Node *ret = InsertAfterNode(node, node->data);
    if (node->next != ret)
    {
        return NULL;
    }
    else
    {
        node->data = data;
        return node;
    }
}

bool LinkedListDeleteAt(LinkedList list, int pos, int *removed)
{
    *removed = -1;
    Node *current = LinkGetAt(list, pos);
    if (current == NULL || current->next == NULL)
        return false;
    Node *removeNode = current->next;
    *removed = removeNode->data;
    current->next = removeNode->next;
    free(removeNode);
    return true;
}

Node *LinkGetAt(LinkedList list, int pos)
{
    if (pos < 1 || list == NULL)
        return NULL;
    Node *current = list;
    for (int i = 1; i < pos && list->next != NULL; ++i)
        current = current->next;
    return current;
}

Node *LinkLocate(LinkedList list, int target)
{
    if (list == NULL)
        return NULL;
    Node *current = list->next;
    while (current != NULL && current->data != target)
        current = current->next;
    return current;
}

int LinkLength(LinkedList list)
{
    int length = 0;
    Node *current = list->next;
    while (current != NULL)
    {
        ++length;
        current = current->next;
    }
    return length;
}

bool ReverseLinkedList(LinkedList list)
{
    if (list == NULL)
        return false;
    Node *prev = NULL;
    Node *next = NULL;
    Node *current = list->next;
    while (current != NULL)
    {
        next = current;
        current = current->next;
        next->next = prev;
        prev = next;
    }
    list->next = prev;
    return true;
}

bool LinkedListInsertHead(LinkedList list)
{
    int data;
    printf("Input a Integer: ");
    scanf("%d", &data);
    while (data != -1)
    {
        if (InsertAfterNode(list, data) == false)
            return false;
        printf("Input a Integer: ");
        scanf("%d", &data);
    }
    return true;
}

bool LinkedListInsertTail(LinkedList list)
{
    int data;
    Node *last = list;
    printf("Input a Integer: ");
    scanf("%d", &data);
    while (data != -1)
    {
        if ((last = InsertAfterNode(last, data)) == NULL)
            return false;
        printf("Input a Integer: ");
        scanf("%d", &data);
    }

    return true;
}

void FreeLinkedList(LinkedList list)
{
    Node *prev = list;
    while (list != NULL)
    {
        list = list->next;
        free(prev);
        prev = NULL;
        prev = list;
    }
}

// --------------Double linkedList definition--------------
DLinkedList InitDLinkedList()
{
    // The double linked list with head node
    DLinkedList dlist = (DLinkedList)malloc(sizeof(DNode));
    if (dlist == NULL)
        return NULL;
    dlist->data = 0;
    dlist->prev = NULL;
    dlist->next = NULL;
    return dlist;
}

bool DLLEmpty(DLinkedList dlist) { return dlist != NULL && dlist->next == NULL; }

DNode *InsertAfterDNode(DNode *dnode, int data)
{
    if (dnode == NULL)
        return NULL;
    DNode *newNode = (DNode *)malloc(sizeof(DNode));
    if (newNode == NULL)
        return NULL;
    newNode->data = data;
    newNode->prev = dnode;
    newNode->next = dnode->next;
    dnode->next = newNode;
    return newNode;
}

DNode *InsertBeforeDNode(DNode *dnode, int data)
{
    if (dnode == NULL)
        return NULL;
    DNode *newNode = (DNode *)malloc(sizeof(DNode));
    if (newNode == NULL)
        return NULL;
    newNode->data = data;
    newNode->next = dnode->next;
    dnode->next = newNode;
    dnode->data = data;
    return dnode;
}

bool DeleteNextDNode(DLinkedList dlist)
{
    // dlist is null or dlist is the last node
    if (dlist == NULL || dlist->next == NULL)
        return false;
    DNode *remove = dlist->next;
    dlist->next = remove->next;
    // remove is not the last node
    if (remove->next != NULL)
        remove->next->prev = dlist;
    free(remove);
    return true;
}

void FreeDLinkedList(DLinkedList dlist)
{
    DNode *remove = dlist;
    while (dlist != NULL)
    {
        dlist = dlist->next;
        free(remove);
        remove = NULL;
        remove = dlist;
    }
}

CLinkedList InitCLinkedList()
{
    CLinkedList clist = (CLinkedList)malloc(sizeof(CLinkedList));
    clist->data = 0;
    clist->next = clist;
    return clist;
}

void FreeCLinkedList(CLinkedList clist) {}

bool CLLEmpty(CLinkedList clist) { return clist->next == clist; }

bool isTail(CLinkedList clist, CNode *cnode) { return cnode->next == clist; }
