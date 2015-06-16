#include <stdio.h>

#include "Environment.h"


int main(int argc, char *argv[])
{
    FILE *fp;
    char ch = 0;
    int count = 0;
    
    if(argc != 2)
    {
        ASSERT(0 && "Command Error");
        return FAILURE;
    }

    fp = fopen(argv[1], "r");

    if(fp == NULL)
    {
        ASSERT(0 && "Read File Error");
        return FAILURE;
    }

    while((ch = getc(fp)) != EOF)
    {
        putchar(ch);
        count++;
    }

    fclose(fp);

    printf("\ncount :%d", count);
}


