#include "linear_list.h"
#include <stdio.h>

int main(int argc, char **args)
{
    SequenceList seq_list;
    InitSequenceList(&seq_list);
    ShowSequenceList(&seq_list, ' ');
    printf("Successfully exit!\n");
    return 0;
}