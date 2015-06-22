/*************************************************************************************************************
    COPYRIGHT AND PERMISSION NOTICE

    Copyright (c) 1996 - 2015, Joe, <Joe.zhenghui@qq.com>.

    All rights reserved.

    Permission to use, copy, modify, and distribute this software for any purpose
    with or without fee is hereby granted, provided that the above copyright
    notice and this permission notice appear in all copies.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT OF THIRD PARTY RIGHTS. IN
    NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
    DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
    OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE
    OR OTHER DEALINGS IN THE SOFTWARE.

    Except as contained in this notice, the name of a copyright holder shall not
    be used in advertising or otherwise to promote the sale, use or other dealings
    in this Software without prior written authorization of the copyright holder.

*************************************************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>

#include "mpeg_ts_stream_log.h"

static int mpeg_ts_steam_WriteLogFile(char *pcString);
static char sacLogPath[256] = {0};

int mpeg_ts_steam_LogInit(char *pcLogPath)
{    
    if(pcLogPath == NULL)
    {
        return -1;
    }

    snprintf(sacLogPath, sizeof(sacLogPath), "%s", pcLogPath);

    if(access(sacLogPath, F_OK) == 0)
    {
        remove(sacLogPath);
    }

    return 0;
}

int mpeg_ts_steam_Printf(char *Format_p, ...)
{
    va_list ap;
    static unsigned char asuc_string[2048] = {0};

    memset(asuc_string, 0, sizeof(asuc_string));

    va_start(ap, Format_p);
    
    vsprintf(asuc_string, Format_p, ap);

    va_end(ap);

    //printf("%s", asuc_string);

    return mpeg_ts_steam_WriteLogFile(asuc_string);
}

static int mpeg_ts_steam_WriteLogFile(char *pcString)
{
    static FILE *pfLogFile = NULL;

    int nRet = 0;
    
    if((pcString==NULL) || (strlen(sacLogPath)==0))
    {
        return 0;
    }

    pfLogFile = fopen(sacLogPath, "a+");

    if(pfLogFile == NULL)
    {
        printf("[%s-%d]---------------->error, sacLogPath=%s\n", __FUNCTION__, __LINE__, sacLogPath);
        return 0;
    }

    nRet = fwrite((void*)pcString, sizeof(char), strlen(pcString), pfLogFile);

    fclose(pfLogFile);

    return nRet;
}






