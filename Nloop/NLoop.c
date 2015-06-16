#include <stdio.h>

typedef struct NloopNode
{
	int m_nNum;
	struct NloopNode* m_psnext;
}NloopNode;

int main(void)
{
	int nNum = 0;

	NloopNode* psHead = NULL;

	psHead = (NloopNode*)malloc(sizeof(NloopNode));

	scanf("%d", &nNum);

	
	for(int i=0; i<nNum; i++)
	{
		NloopNode* psNode = (NloopNode*)malloc(sizeof(NloopNode));
		NloopNode* psNewNode = psHead;

		psNode->m_nNum = i;

		while(psNewNode->m_psnext == NULL)
		{
			
		}
	}
}
