#include <stdio.h>

//using namespace std;

void main(void)
{
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	
	int n = 0;

	for(n=1000; n<10000; n++)
	{
		int i = n*9;

		//n *= 9;

		a = n/1000;
		b = n/100 - a*10;
		c = n/10 - a*100 - b*10;
		d = n%10;

		if((d*1000+b*100+c*10+a) == i)
		{
			printf("the antitone number is : %d, and ori number is :%d, %d,%d,%d,%d\n", n, i, a,b,c,d);	
		}
	}
}
