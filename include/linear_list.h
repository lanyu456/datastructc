#ifndef __LINEAR_LIST_H__
#define __LINEAR_LIST_H__

#define MaxSize 10

typedef struct
{
    int data[MaxSize];
    int length;
} SequenceList;

void InitSequenceList(SequenceList *L);

void ShowSequenceList(SequenceList *L, char sep);

#endif // __LINEAR_LIST_H__