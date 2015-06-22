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

#include "mpeg_ts_stream_read.h"

static ts_packet_callback sgTsPacketCallBack = NULL; 

int mpeg_ts_stream_read(char *pcStreamPath, ts_packet_callback pfTsPacketCallBack)
{
    int i =0;
    int j = 0;
    int nCount = 0;
    long lStreamLen = 0;
    FILE *psStreamhandle = NULL;
    unsigned char aucData[mpeg_ts_stream_packet_len] = {0};

    if(!pcStreamPath || !pfTsPacketCallBack)
    {
        mpeg_ts_steam_Printf("[%s-%d]------->err para\n", __FUNCTION__, __LINE__);
        return -1;
    }

    sgTsPacketCallBack = pfTsPacketCallBack;

    psStreamhandle = fopen(pcStreamPath, "r");

    if(psStreamhandle == NULL)
    {
        mpeg_ts_steam_Printf("[%s-%d]------->read stream file error\n", __FUNCTION__, __LINE__);
        return -1;
    }

    fseek(psStreamhandle, 0, SEEK_END);

    lStreamLen = ftell(psStreamhandle);
    
    fseek(psStreamhandle, 0, SEEK_SET);
    
    mpeg_ts_steam_Printf("[%s-%d]------->read stream file len = %ld\n", __FUNCTION__, __LINE__, lStreamLen);
    
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
            sgTsPacketCallBack(aucData, mpeg_ts_stream_packet_len);
            nCount++;
        }
        else
        {
            mpeg_ts_steam_Printf("[%s-%d]------->read stream file error\n", __FUNCTION__, __LINE__);
        }
    }

    mpeg_ts_steam_Printf("[%s-%d]------->read stream section number: nCount = %d\n", __FUNCTION__, __LINE__, nCount);

    fclose(psStreamhandle);

    return 0;
}



