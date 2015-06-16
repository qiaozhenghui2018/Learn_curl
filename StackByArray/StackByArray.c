#include "StackByArray.h"

STACK_ARRAY_S *CreateStack(int nElementNum)
{
    STACK_ARRAY_S* psStack = NULL;

    psStack = (STACK_ARRAY_S*)calloc(sizeof(STACK_ARRAY_S), 1);

    if(psStack == NULL)
    {
        ASSERT(psStack != NULL);
        return NULL;
    }

    psStack->m_nCapacity = nElementNum;

    psStack->m_pStack = (BYTE*)calloc(sizeof(BYTE), nElementNum);

    if(psStack == NULL)
    {
        ASSERT(psStack->m_pStack != NULL);
        return NULL;
    }

    psStack->m_nTopOfStack = STACK_EMPTY_FLAG;

    return psStack;
}

int DisposeStack(STACK_ARRAY_S* psStack)
{
    if(psStack == NULL)
    {
        return FAILURE;
    }

    free(psStack->m_pStack);
    free(psStack);

    return SUCCESS;
}

int Push(STACK_ARRAY_S * psStack,BYTE ucKey)
{
    if(psStack == NULL)
    {
        ASSERT(psStack != NULL);
        return FAILURE;
    }

    psStack->m_pStack[++psStack->m_nTopOfStack] = ucKey;

    return SUCCESS;
}

int Pop(STACK_ARRAY_S * psStack, BYTE* pucKey)
{
    if((psStack == NULL) || (psStack->m_nTopOfStack == STACK_EMPTY_FLAG))
    {
        ASSERT(psStack != NULL);
        ASSERT(psStack->m_nTopOfStack != STACK_EMPTY_FLAG);
        return FAILURE;
    }

    *pucKey = psStack->m_pStack[psStack->m_nTopOfStack--];

    return SUCCESS;
}


/*以下为测试代码*/

int main(int argc, char* argv[])
{
    STACK_ARRAY_S* psStack = NULL;
    int nNum = 256;
    int i =0;
    BYTE ucKey = 0;

    psStack = CreateStack(nNum);

    while(i<nNum)
    {
        Push(psStack, i++);
        printf("Push i:%X\n", i-1);
    }

    while(psStack->m_nTopOfStack != STACK_EMPTY_FLAG)
    {
        Pop(psStack, &ucKey);
        printf("Pop ucKey:%X\n", ucKey);
    }

    DisposeStack(psStack);

    return 0;
}

