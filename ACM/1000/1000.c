#include "Environment.h"

static INT CulatePlus(INT nNumA, INT NUMB, INT *pnAnswer);

INT main()
{
	INT nRet = FAILURE;
	INT nNumA = 0;
	INT nNumB = 0;
	INT nAnswer = 0;
	
	scanf("%d%d", &nNumA, &nNumB);

	if((nNumA < 0) || (nNumB > 10))
	{
		//ASSERT(nNumA >= 0);
		//ASSERT(nNumB <= 10);
		return FAILURE;
	}

	if(CulatePlus(nNumA, nNumB, &nAnswer) != SUCCESS)
	{
		ASSERT(0 && "Culate Error");
		return FAILURE;
	}
	
	//printf("Answer : %d\n", nAnswer);
	
	return nAnswer;
}

static INT CulatePlus(INT nNumA, INT NUMB, INT *pnAnswer)
{
	INT nRet = FAILURE;

	if(NULL == pnAnswer)
	{
		//ASSERT(NULL != pnAnswer);
		return FAILURE;
	}

	*pnAnswer = nNumA + NUMB;

	return SUCCESS;
}


