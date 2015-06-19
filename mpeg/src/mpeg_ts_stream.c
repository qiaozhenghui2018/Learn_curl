/*************************************************************************************************************


















*************************************************************************************************************/

#include <stdio.h>
#include <string.h>

#include "mpeg_ts_stream.h"

int mpeg_ts_stream_read(char *pcStreamPath)
{
    int i =0;
    int j = 0;
    int nCount = 0;
    long lStreamLen = 0;
    FILE *psStreamhandle = NULL;
    unsigned char aucData[mpeg_ts_stream_packet_len] = {0};

    if(pcStreamPath == NULL)
    {
        mpeg_ts_steam_write("[%s-%d]------->err para\n", __FUNCTION__, __LINE__);
        return -1;
    }

    psStreamhandle = fopen(pcStreamPath, "r");

    if(psStreamhandle == NULL)
    {
        mpeg_ts_steam_write("[%s-%d]------->read stream file error\n", __FUNCTION__, __LINE__);
        return -1;
    }

    fseek(psStreamhandle, 0, SEEK_END);

    lStreamLen = ftell(psStreamhandle);
    
    fseek(psStreamhandle, 0, SEEK_SET);
    
    mpeg_ts_steam_write("[%s-%d]------->read stream file len = %ld\n", __FUNCTION__, __LINE__, lStreamLen);
    
    fread(aucData, mpeg_ts_stream_packet_len, 1, psStreamhandle);

    /*find the sync tag*/
    if(aucData[0] != mpeg_ts_stream_packet_tag)
    {
        for(i=0; i<mpeg_ts_stream_packet_len; i++)
        {
            if(aucData[i] == mpeg_ts_stream_packet_len)
            {
                fseek(psStreamhandle, i, SEEK_SET);
            }
        }
    }

    for(j=0; j<(lStreamLen-i-1)/mpeg_ts_stream_packet_len; j++)
    {
        fseek(psStreamhandle, i+j*mpeg_ts_stream_packet_len, SEEK_SET);
        
        fread(aucData, mpeg_ts_stream_packet_len, 1, psStreamhandle);
        
        if(aucData[0] == mpeg_ts_stream_packet_tag)
        {
            nCount++;
        }
        else
        {
            mpeg_ts_steam_write("[%s-%d]------->read stream file error\n", __FUNCTION__, __LINE__);
        }
    }

    mpeg_ts_steam_write("[%s-%d]------->read stream section number: nCount = %d\n", __FUNCTION__, __LINE__, nCount);

    fclose(psStreamhandle);

    return 0;
}


/*
*./a.out stream.ts logpath
*/
int main(int argc, char *argv[])
{
    int i = 0;
    int j = 0;

    for(i=0; i<argc; i++)
    {
        printf("--->argv[%d] = %s\n", i, argv[i]);
    }

    mpeg_ts_steam_Init(argv[2]);

    mpeg_ts_stream_read(argv[1]);

    return 0;
}



