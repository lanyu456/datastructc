#ifndef __STACK_H__
#define __STACK_H__

#include "linear_list.h"

bool InitStack(Stack *stack) { return InitSequenceList(stack); }
bool Push(Stack *stack, int value) { return SequencePush(stack, value); }
int Pop(Stack *stack) { return SequencePop(stack); }
int Peek(Stack *stack) { return stack->data[stack->length - 1]; }
bool StackEmpty(Stack *stack) { return SeqEmpty(stack); }
bool FreeStack(Stack *stack) { FreeSequenceList(stack); }

#endif // __STACK_H__