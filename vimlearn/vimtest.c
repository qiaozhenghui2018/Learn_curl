#include <stdio.h>

int main()
{
	    int t = 0;
		int n = 0, i = 0, m = 0;
		int a[40] = {0};
		
		printf("Please input the times: \n");
		scanf("%d", &t);
		printf("The times you have input is %d \n", t);

		while(t--)
		{
			printf("Please input the number:\n");

			scanf("%d", &n);
			
			printf("the number you have input is : %d\n", n);

			i = 0;

			while(n!=0)
			{
				a[i]=n%2;
				n = n/2;
				i++;
			}

			m = i-1;

			for(i=m;i>=0;i--)
			{
				printf("%d", a[i]);
			}

			printf("\n");
		}

		return 0;
}
