
#include "List.h"

int main(int argc, char *argv[])
{
    int nCommand = 0;
    Node_S *psHead = NULL;

    while(TRUE)
    {
        printf("0:create one list that have 100 Nodes and put in num;\n1:insert 200 after 50th node;\n2:delete the 51th node;\n3:printf the whole node in the list\n");
        
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
                
                for(i=0; i<100; i++)
                {
                    if(MakeNode(&psNodeTemp) != SUCCESS)
                    {
                        ASSERT(0 && "Create Node Error");
                        return -1;
                    }
                
                    psNodeTemp->m_sData = ++i;
                
                    if(InsertNode(i, psHead, psNodeTemp) != SUCCESS)
                    {
                        ASSERT(0 && "Insert Node Error");
                        return -1;
                    }
                }
            }

            case 1:
            {
                
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
            }

            default :
            {
                printf("\n Error Input");
            }
        }
    }
}


