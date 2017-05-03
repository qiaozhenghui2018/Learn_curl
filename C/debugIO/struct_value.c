
#include <stdio.h>

typedef struct
{
    short a;
    int b;
    char c;
}test;

int main(void)
{
    test A, B;

    test* C = NULL;
    A.a = 1;
    A.b = 2;
    A.c = 3;

    B = A;

    printf("a-b-c = %d-%d-%d\n", B.a, B.b, B.c);

    return 0;
}
