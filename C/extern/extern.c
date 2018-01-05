#include<stdio.h>

char g_cBuf[] = "extern test";
char *ptr = "test";

void addr(void)
{
    printf("buf=%p, ptr=%p\n", g_cBuf, ptr);
}

