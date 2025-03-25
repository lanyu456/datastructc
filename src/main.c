#include "linear_list.h"
#include "stack.h"
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
        SequencePush(&seq_list, RAND_BETWEEN(50, 100));

    printf("--Initial list: \n");
    ShowSequenceList(&seq_list, ' ');
    SequenceListInsertAt(&seq_list, 0, 999);
    SequenceListInsertAt(&seq_list, 0, 998);

    printf("--Insert 998 and 999 to the head of list: \n");
    ShowSequenceList(&seq_list, ' ');
    int ret = 0;
    SequenceListDeleteAt(&seq_list, 0, &ret);

    printf("--The delete value is %d\n", ret);

    printf("--Pop all elements:\n");
    while (seq_list.length > 0)
        printf("%d ", SequencePop(&seq_list));

    printf("\n");
    FreeSequenceList(&seq_list);

    printf("--------------Test linked list--------------\n");
    // LinkedList list = InitLinkedList();
    // LinkedListInsertHead(list);
    // ShowLinkedList(list);
    // printf("list length is %d\n", LinkLength(list));
    // FreeLinkedList(list);

    // LinkedList head = InitLinkedList();
    // LinkedListInsertTail(head);
    // ShowLinkedList(head);
    // printf("list length is %d\n", LinkLength(head));
    // ReverseLinkedList(head);
    // printf("Reversed linked list:");
    // ShowLinkedList(head);
    // printf("list length is %d\n", LinkLength(head));
    // FreeLinkedList(head);

    printf("--------------Test stack--------------\n");
    Stack stack;
    InitStack(&stack);
    int data;
    printf("Input a Integer: ");
    scanf("%d", &data);
    while (data != -1)
    {
        Push(&stack, data);
        printf("Input a Integer: ");
        scanf("%d", &data);
    }

    printf("peek: %d\n", Peek(&stack));
    while (!StackEmpty(&stack))
        printf("%d ", Pop(&stack));
    FreeStack(&stack);

    printf("\nSuccessfully exit!\n");

    return 0;
}