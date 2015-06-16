
#ifndef __STACK_BY_ARRAY_H__
#define __STACK_BY_ARRAY_H__

#include "Environment.h"

#define STACK_BY_ARRAY_MAX_NUM      (100)

#define STACK_EMPTY_FLAG        (-1)

typedef struct _STACK_ARRAY
{
    int     m_nCapacity;
    int     m_nTopOfStack;
    BYTE*   m_pStack;
}STACK_ARRAY_S;

STACK_ARRAY_S *CreateStack(int nElementNum);
int DisposeStack(STACK_ARRAY_S* psStack);

int Push(STACK_ARRAY_S* psStack, BYTE ucKey);

int Pop(STACK_ARRAY_S* psStack, BYTE *pucKey);

#endif

