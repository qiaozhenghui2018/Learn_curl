#include "StackByList.h"

int CreateStack(Stack **psStack)
{
    /*
    if(psStack == NULL || *psStack == NULL)
    {
        ASSERT(0 && "Input Paramemters Error");
        return FAILURE;
    }
    */
    *psStack = calloc(1, sizeof(Stack));

    if(*psStack == NULL)
    {
        ASSERT(*psStack != NULL);
        return FAILURE;
    }

    return SUCCESS;
}

int IsStackEmpty(Stack * psStack)
{
    if(psStack == NULL)
    {
        ASSERT(psStack != NULL);
        return FAILURE;
    }

    return (psStack->m_spNext == NULL)?TRUE:FALSE;
}

int MakeStackEmpty(Stack *psStack)
{
    int nKeyValue = 0;
    int nRet = FAILURE;
    
    if(psStack == NULL)
    {
        ASSERT(psStack != NULL);
        return FAILURE;
    }

    while(psStack->m_spNext != NULL)
    {
        nRet = Pop(psStack, &nKeyValue);

        ASSERT(nRet == SUCCESS);
    }

    return SUCCESS;
}

int Push(Stack * psStack,int nKey)
{
    Node_S *psNode = NULL;
        
    if(psStack == NULL)
    {
        ASSERT(psStack != NULL);
        return FAILURE;
    }

    psNode = calloc(1, sizeof(Node_S));

    //printf("\npsNode:%p", psNode);

    if(psNode == NULL)
    {
        ASSERT(psNode != NULL);
        return FAILURE;
    }

    psNode->m_nElement = nKey;

    psNode->m_spNext = psStack->m_spNext;
    psStack->m_spNext = psNode;

    return SUCCESS;
}

int Pop(Stack * psStack,int * pnKey)
{
    Node_S *psNode = NULL;
    
    if((psStack == NULL) || (pnKey == NULL))
    {
        ASSERT(psStack != NULL);
        ASSERT(pnKey != NULL);
        return FAILURE;
    }

    if(IsStackEmpty(psStack))
    {
        ASSERT(0 && "The Stack is Empty");
        return FAILURE;
    }

    psNode = psStack->m_spNext;

    *pnKey = psNode->m_nElement;

    psStack->m_spNext = psNode->m_spNext;

    free(psNode);

    return SUCCESS;
}

int Top(Stack * psStack,int * pnkey)
{
    if((psStack == NULL)||(pnkey == NULL))
    {
        ASSERT(psStack != NULL);
        ASSERT(pnkey != NULL);
        return FAILURE;
    }

    if(IsStackEmpty(psStack))
    {
        ASSERT(0 && "The Stack Is Empty");
        return FAILURE;
    }

    *pnkey = psStack->m_spNext->m_nElement;

    return SUCCESS;
}

int main(int argc, char *argv[])
{
    Stack *psStack = NULL;
    int nNum = 10;
    int nOutValue = 0;

    if(CreateStack(&psStack) != SUCCESS)
    {
        ASSERT(0 && "Create Stack Error");
        return FAILURE;
    }

    ASSERT(psStack != NULL);

    while(nNum)
    {
        if(Push(psStack, nNum) != SUCCESS)
        {
            ASSERT(0 && "Add to Stack Error");
        }

        //printf("\nAdd to Stack nNum:%d", nNum);

        if(Top(psStack, &nNum) == SUCCESS)
        {
            printf("\n Top nNum:%d", nNum);
        }

        nNum--;
    }

    while(psStack->m_spNext != NULL)
    {
        if(Pop(psStack, &nOutValue) != SUCCESS)
        {
            ASSERT(0 && "Pop Stack Error");
        }

        printf("\nOut From Stack Is %d", nOutValue);
    }

    return SUCCESS;
}

