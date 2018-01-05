#include<stdio.h>

int main(void)
{
    int i = 10;
    int j = 20;

    printf("i=%d, j=%d\n", i, j);
    printf("1<2?:0 return %d\n", i<j?:0);
    printf("i?:j return %d\n", i?:j);
    
    return 0;
}
