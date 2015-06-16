#ifndef _STACK_LIST_H_
#define _STACK_LIST_H_

#include "Environment.h"

typedef struct _Node
{
    int     m_nElement;

    struct _Node   *m_spNext;
}Node_S;

typedef Node_S  Stack;

int CreateStack(Stack **psStack);

int IsStackEmpty(Stack *psStack);

int MakeStackEmpty(Stack *psStack);

int Push(Stack *psStack, int nKey);

int Pop(Stack *psStack, int *pnKey);

int Top(Stack *psStack, int *pnkey);

#endif
