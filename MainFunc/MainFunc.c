#include "Environment.h"

int main(int argc, char *argv[])
{
	INT i = 0;

	if(atoi(argv[1]) < 0)
	{
		ASSERT(argv[1] >= 0);
		return FAILURE;
	}

	i = atoi(argv[1]);

    printf("argc:%d\n. argv[0]:%s\n, argv[1]:%s\n, argv[2]:%s\n", argc, argv[0], argv[1], argv[2]);

    while(strcmp((char*)argv[3], "Forever") == 0)
    {
        printf("This is Forever print!!!\n");
        sleep(1);
    }

    while(strcmp((char*)argv[1], "HardWorkAndStudy") == FALSE)
 	{
		printf("i wanted to study in \n");
	}

	while(i-- > 0)
 	{
		printf("i wanted to study in \n");
	}
}
