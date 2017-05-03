
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*using ' ' repleace '\n'*/
static void adv_process_specialchar(char* s)
{
    char* d;
    char *sp;
    char* t = NULL;
    if(!s) return;

    d = s;
    t = (char*)calloc(1, strlen(s)+1);
    sp = t;
    if(!t) return;
    
    while(*s != '\0')
    {
        switch(*s)
        {
            case '\n' : s++; break;
            default : *t++ = *s++;break;
        }
    }
    strcpy(d, sp);
    d[strlen(sp)] = '\0';

    free(sp);
}

int main(int argc, char* argv[])
{
	char str[128] = {"\n1\n2\n3\n4\n5"};
	printf("before str = %s\n", str);
	adv_process_specialchar(str);
	printf("after str = %s\n", str);
}