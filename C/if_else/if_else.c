
#include <stdio.h>

int main(void)
{
    int i = 1; 
    int j = 0;
    int k = 3;

    if(i<j)
        printf("i<j\n");
    else if(i<k)
        printf("i<k\n");
    else
        printf("else\n");

    return printf("end\n");
}
