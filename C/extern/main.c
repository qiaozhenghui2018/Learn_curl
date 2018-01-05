#include <stdio.h>

extern char *g_cBuf;
extern char* ptr;

extern void addr(void);

int main(void)
{
    addr();

    printf("main:buf=%p, ptr=%p\n", g_cBuf, ptr);
}
