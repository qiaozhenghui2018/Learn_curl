/*************************************************************************************************************


















*************************************************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdarg.h>

#include "mpeg_ts_stream_log.h"

static int mpeg_ts_steam_WriteLogFile(char *pcString);
static char sacLogPath[256] = {0};

int mpeg_ts_steam_Init(char *pcLogPath)
{
    if(pcLogPath == NULL)
    {
        return -1;
    }

    snprintf(sacLogPath, sizeof(sacLogPath), "%s/%s", pcLogPath, "mpeg_ts_stream.log");

    return 0;
}

int mpeg_ts_steam_write(char *Format_p, ...)
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






