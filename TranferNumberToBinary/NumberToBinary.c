#include "Environment.h"

#define MAIN_MAX_BIE    (40)

INT main()
{
    INT nCycles = 0;
    INT i = 0;
    
    DWORD dwNum = 0;

    BYTE aucBinary[MAIN_MAX_BIE] = {0};

    printf("please inout the nCycles\n");

    scanf("%d", &nCycles);

    printf("nCycles : %d\n", nCycles);

    while(nCycles--)
    {
        i = 0;
        dwNum = 0;
        
        printf("please input the number\n");

        scanf("%d", &dwNum);

        printf("the Number:%d\n", dwNum);
        
        while(dwNum != 0)
        {
            aucBinary[i++] = dwNum%2;//此处运算到最后多加了一个1
            dwNum = dwNum/2;
        }

        i--;
        
        printf("After tranfer, the number's binary is:\n");
        
        while(i >= 0)
        {
            printf("%d", aucBinary[i--]);
        }

        printf("\n");
    }
}
