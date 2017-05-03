
#include <stdio.h>

int main(void)
{
    unsigned short a = 0x8bec;

    printf("signed = 0x%04x, unsigned = 0x%04x\n", (signed short)a, (unsigned short)a);

    return 0;
}
