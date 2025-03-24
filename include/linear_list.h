#ifndef __LINEAR_LIST_H__
#define __LINEAR_LIST_H__

#define InitSize 10

typedef struct
{
    int *data;
    int max_size;
    int length;
} SequenceList;

void InitSequenceList(SequenceList *L);

void ShowSequenceList(SequenceList *L, char sep);

#endif // __LINEAR_LIST_H__