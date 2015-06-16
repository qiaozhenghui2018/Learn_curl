#ifndef _ENVIRONMENT_H_
#define _ENVIRONMENT_H_

#include <stdio.h>

#define ASSERT(expression)  if (!expression)\
								{\		
                                	printf("ASSERTION (%s) Failed at file:%s, line:%d\n", #expression, __FILE__, __LINE__);\
								}

#define TRUE        (1)
#define FALSE       (0)
#define SUCCESS     (1)
#define FAILURE     (-1)

typedef char            CHAR;
typedef unsigned char   BYTE;
typedef unsigned short  WORD;
typedef unsigned int    DWORD;
typedef int             INT;

#endif//_ENVIRONMENT_H_

