#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define ASSERT(expression)  if (!expression)\
                                printf("ASSERTION FAILED at file:%s, line:%d\n", __FILE__, __LINE__);

#define TRUE        (1)
#define FALSE       (0)
#define SUCCESS     (1)
#define FAILURE     (-1)

typedef char            CHAR;
typedef unsigned char   BYTE;
typedef unsigned short  WORD;
typedef unsigned int    DWORD;
typedef int             INT;


