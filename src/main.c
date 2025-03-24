#include "linear_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RAND_BETWEEN(min, max) (rand() % (max - min + 1) + min)
int main(int argc, char **args)
{
    srand(time(NULL));
    printf("--------------Test linear list--------------\n");
    SequenceList seq_list;
    InitSequenceList(&seq_list);
    for (int i = 0; i < 10; i++)
        sq_push(&seq_list, RAND_BETWEEN(50, 100));

    printf("--Initial list: \n");
    ShowSequenceList(&seq_list, ' ');
    ListInsert(&seq_list, 0, 999);
    ListInsert(&seq_list, 0, 998);

    printf("--Insert 998 and 999 to the head of list: \n");
    ShowSequenceList(&seq_list, ' ');
    int ret = 0;
    ListDelete(&seq_list, 0, &ret);

    printf("--The delete value is %d\n", ret);

    printf("--Pop all elements:\n");
    while (seq_list.length > 0)
        printf("%d ", sq_pop(&seq_list));

    printf("\n");
    FreeSequenceList(&seq_list);
    printf("Successfully exit!\n");
    return 0;
}