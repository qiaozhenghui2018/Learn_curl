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

#include "mpeg_ts_stream_read.h"
#include "mpeg_ts_stream_log.h"

static unsigned char saucPatTable[mpeg_ts_stream_max_section_len] = {0};
static int snPatTableLen = 0;

static int process_ts_packet(unsigned char *pucData, unsigned int dwLen)
{
    ts_packet_header sPacketHeader; 
    static unsigned int dwContinueCount = 0;

    memset(&sPacketHeader, 0, sizeof(ts_packet_header));
    
    if(!pucData)
    {
        mpeg_ts_steam_Printf("------->call back para error\n");
        return -1;
    }

    sPacketHeader.transport_error_indicator        = pucData[1] >>  7; 
    sPacketHeader.payload_unit_start_indicator    = pucData[1] >>  6 &  0x01; 
    sPacketHeader.transport_priority                = pucData[1] >>  5 &  0x01; 
    sPacketHeader.PID                            = (pucData[1] &  0x1F) <<  8 | pucData[ 2]; 
    sPacketHeader.transport_scrambling_control    = pucData[3] >>  6; 
    sPacketHeader.adaption_field_control            = pucData[3] >>  4 &  0x03; 
    sPacketHeader.continuity_counter                = pucData[3] &  0x03; 
    
    if(sPacketHeader.PID==mpeg_ts_stream_nit_pid && sPacketHeader.transport_error_indicator!=1)
    {   
        mpeg_ts_steam_Printf("------->sPacketHeader.payload_unit_start_indicator:%d\n", sPacketHeader.payload_unit_start_indicator);
        mpeg_ts_steam_Printf("------->sPacketHeader.adaption_field_control:%d\n", sPacketHeader.adaption_field_control);
        /*psi data start*/
        if(sPacketHeader.payload_unit_start_indicator==1 && sPacketHeader.adaption_field_control==1)
        {
            unsigned short wSectionLen = 0;
            
            mpeg_ts_steam_Printf("------->sPacketHeader.continuity_counter:%d\n", sPacketHeader.continuity_counter);
            
            dwContinueCount = sPacketHeader.continuity_counter;

            snPatTableLen = mpeg_ts_stream_packet_payload_len;
            
            memcpy(saucPatTable, &pucData[mpeg_ts_stream_packet_header_len+1], snPatTableLen);

            wSectionLen = (saucPatTable[1]&0x0F)<<8 | saucPatTable[2];

            if(wSectionLen+3 < mpeg_ts_stream_packet_payload_len)
            {
                {
                    int i =0;
                    
                    mpeg_ts_steam_Printf("------->pat table, len = %d :\n", wSectionLen);
                    for(i=0; i<snPatTableLen; i++)
                    {
                        mpeg_ts_steam_Printf(" %02x", saucPatTable[i]);
                    }
                    mpeg_ts_steam_Printf("\n");
                    
                    dwContinueCount = 0;
                    snPatTableLen = 0;
                    memset(saucPatTable, 0, sizeof(saucPatTable));
                }
            }
        }
        else
        {
            /*next psi ts packet*/
            if(dwContinueCount++ == sPacketHeader.continuity_counter)
            {
                snPatTableLen += mpeg_ts_stream_packet_payload_len;
                
                memcpy(&saucPatTable[snPatTableLen], &pucData[mpeg_ts_stream_packet_payload_len], snPatTableLen);
            }
            else
            {        
                {
                    int i =0;
                    
                    mpeg_ts_steam_Printf("------->pat table:\n");
                    for(i=0; i<snPatTableLen; i++)
                    {
                        mpeg_ts_steam_Printf(" %02x", saucPatTable[i]);
                    }
                    mpeg_ts_steam_Printf("\n");
                    
                    dwContinueCount = 0;
                    snPatTableLen = 0;
                    memset(saucPatTable, 0, sizeof(saucPatTable));
                }
                mpeg_ts_steam_Printf("\n------->continue counter is error\n");
            }
        }
            
        mpeg_ts_steam_Printf("------->sPacketHeader.payload_unit_start_indicator = %d\n", sPacketHeader.payload_unit_start_indicator);
        mpeg_ts_steam_Printf("------->sPacketHeader.adaption_field_control = %d\n", sPacketHeader.adaption_field_control);
        mpeg_ts_steam_Printf("------->sPacketHeader.transport_error_indicator   = %d\n", sPacketHeader.transport_error_indicator  );
        
        //mpeg_ts_steam_Printf("\n------->end\n");
    }
        
    return 0;
}

/*
*./a.out stream.ts ./stream.log
*/
int main(int argc, char *argv[])
{
    int i = 0;
    int j = 0;

    for(i=0; i<argc; i++)
    {
        printf("--->argv[%d] = %s\n", i, argv[i]);
    }

    mpeg_ts_steam_LogInit(argv[2]);

    mpeg_ts_stream_read(argv[1], process_ts_packet);

    return 0;
}

