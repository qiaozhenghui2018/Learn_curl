#include <stdio.h>
#include <stdarg.h>
#include <string.h>

int debug(char msg, ...)
{
    va_list ap;
    int i = 0;
    char *para = NULL;

    va_start(ap, msg);

    while(1)
    {
        para = va_arg(ap, char*);

        printf("para %d is %s\n", i++, para);

        //if(!strcmp(para, "test"))
            //break;
    }

    va_end(ap);
}

int main(int argc, char* argv[])
{
    return debug("qiao", "zheng", "hui", "arg", "test");
}
