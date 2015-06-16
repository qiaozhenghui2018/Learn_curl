#include "List.h"

static Node_S* FindPreviousNode(Node_S *psNode, Node_S *psHead);

int MakeNode(Node_S **psListHead)
{
	if(psListHead == NULL)
	{
        ASSERT(0 && "Create Node Error");
        return FAILURE;
	}

    *psListHead = (Node_S*)malloc(sizeof(Node_S));

    if(psListHead == NULL)
    {
        ASSERT(0 && "Create Node Error");
        return FAILURE;
    }

    memset(*psListHead, 0, sizeof(Node_S));

    return SUCCESS;
}

INT IsEmpty(Node_S *psHeadNode)
{
/*
	if(psHeadNode->m_psNext == NULL)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
*/
	/*完全可以这样实现*/
	return psHeadNode->m_psNext == NULL;
}

INT IsLastNode(Node_S *psNode)
{
/*
	if(Node.m_psNext == NULL)
	{
		return TRUE;
	}
	else
	{
        return FALSE;
    }
*/
	/*简化代码*/
	return psNode->m_psNext == NULL;
}

/*find one node who's data is dwData*/
Node_S* FindNode(NodeData_S sData, Node_S *psHead)
{
	Node_S *psTempNode = NULL;
	
    if(psHead == NULL)
    {
		ASSERT(psHead != NULL);
		return NULL;
    }

    printf("\nsData:%02x", sData);

	psTempNode = psHead;

	/*从头开始查询，查询到第一个截止*/
	while((psTempNode->m_psNext != NULL) && (psTempNode->m_sData != sData))
	{
		psTempNode = psTempNode->m_psNext;
	}

	if(psTempNode == NULL)
	{
		ASSERT(psTempNode != NULL);
		return NULL;
	}

	return psTempNode;//这里返回的不是栈内存的地址，而是链表中节点的地址
}

/*find the previous Node of the list*/
static Node_S* FindPreviousNode(Node_S *psNode, Node_S *psHead)
{
	Node_S *psTempNode = NULL;

	if((psNode == NULL) || (psHead == NULL))
	{
		ASSERT(psNode != NULL);
		ASSERT(psHead != NULL);
		return NULL;
	}

	psTempNode = psHead;

	while(psTempNode->m_psNext != psNode)
	{
		if(psTempNode->m_psNext != NULL)
		{
			psTempNode = psTempNode->m_psNext;
		}
		else
		{
			ASSERT(0 && "the node is the last node");
			return NULL;
		}
	}

	return psTempNode;
}

INT DeleteNode(NodeData_S sData, Node_S *psHead)
{
	Node_S *psNodePrevious = NULL;
	Node_S *psNodeTemp = NULL;

	if(psHead == NULL)
	{
		ASSERT(psHead != NULL);
		return FAILURE;
	}

	psNodeTemp = FindNode(sData, psHead);

	if(IsLastNode(psNodeTemp))
	{
		ASSERT(0 && "the node is the last node");
		return FAILURE;
	}

	psNodePrevious = FindPreviousNode(psNodeTemp, psHead);

	if(psNodePrevious == NULL)
	{
		ASSERT(psNodePrevious != NULL);
		return FAILURE;
	}

	psNodePrevious->m_psNext = psNodeTemp->m_psNext;

	free(psNodeTemp);//free the specified node

	return SUCCESS;
}

int InsertNode(NodeData_S sData, Node_S *psHead, Node_S *psNode)
{
    Node_S *psNodeTemp = NULL;
    
    if((psHead==NULL)||(psNode==NULL))
    {
        ASSERT(psHead != NULL);
        ASSERT(psNode != NULL);
        return FAILURE;
    }

    psNodeTemp = FindNode(sData, psHead);

    if(psNodeTemp == NULL)
    {
        ASSERT(psNode != NULL);
        return FAILURE;
    }

    psNode->m_psNext = psNodeTemp->m_psNext;

    psNodeTemp->m_psNext = psNode;

    return SUCCESS;
}

int main(int argc, char *argv[])
{
    int nCommand = 0;
    Node_S *psHead = NULL;

    while(TRUE)
    {
        printf("\n0:create one list that have 100 Nodes and put in num;\n1:insert 200 after 50th node;\n2:delete the 51th node;\n3:printf the whole node in the list\n");
        
        scanf("%d", &nCommand);

        switch(nCommand)
        {
            case 0:
            {
                Node_S *psNodeTemp = NULL;
                int i = 0;
                
                if(MakeNode(&psHead) != SUCCESS)
                {
                    ASSERT(0 && "Create Node Error");
                    return -1;
                }
                
                psHead->m_sData = 0;
                
                for(i=0; i<101; i++)
                {
                    if(MakeNode(&psNodeTemp) != SUCCESS)
                    {
                        ASSERT(0 && "Create Node Error");
                        return -1;
                    }

                    printf("\nthis is the i:%d", i);
                
                    psNodeTemp->m_sData = i+1;
                
                    if(InsertNode(i, psHead, psNodeTemp) != SUCCESS)
                    {
                        ASSERT(0 && "Insert Node Error");
                        return -1;
                    }
                }

                break;
            }

            case 1:
            {
                Node_S *psNodeTemp = NULL;
                
                if(MakeNode(&psNodeTemp) != SUCCESS)
                {
                    ASSERT(0 && "Create Node Error");
                    return -1;
                }

                psNodeTemp->m_sData = 200;

                if(InsertNode(50, psHead, psNodeTemp) != SUCCESS)
                {
                    ASSERT(0 && "Insert Node Error");
                    return -1;
                }

                break;
            }

            case 2:
            {
                if(DeleteNode(50, psHead) != SUCCESS)
                {
                    ASSERT(0 && "Insert Node Error");
                    return -1;
                }

                break;
            }

            case 3:
            {
                Node_S *psNodeTemp = psHead;

                printf("\nthe num in the list is:\n");
                
                while(psNodeTemp->m_psNext != NULL)
                {
                    printf("%02x\n", psNodeTemp->m_sData);
                    
                    psNodeTemp = psNodeTemp->m_psNext;
                }

                break;
            }

            default :
            {
                if(DeleteNode(nCommand, psHead) != SUCCESS)
                {
                    ASSERT(0 && "Insert Node Error");
                    return -1;
                }

                printf("\n Error Input nCommand:%02x", nCommand);

                break;
            }
        }
    }
}

