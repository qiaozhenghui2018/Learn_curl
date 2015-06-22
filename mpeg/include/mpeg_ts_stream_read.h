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

#ifndef __MPGE_TS_STREAM_H__
#define __MPGE_TS_STREAM_H__

#define mpeg_ts_stream_packet_len                   (188)
#define mpeg_ts_stream_packet_header_len            (4)
#define mpeg_ts_stream_packet_payload_len            (mpeg_ts_stream_packet_len - mpeg_ts_stream_packet_header_len)
#define mpeg_ts_stream_packet_tag                   (0x47)
#define mpeg_ts_stream_nit_pid                      (0x10)
#define mpeg_ts_stream_pat_pid                      (0x00)

#define mpeg_ts_stream_max_section_len              (4096)

// Transport packet header
typedef struct _ts_packet_header
{
    unsigned sync_byte                                         :    8;    //同步字节，固定为0x47 ，表示后面的是一个TS分组，当然，后面包中的数据是不会出现0x47的
    unsigned transport_error_indicator              :    1;      //传输错误标志位，一般传输错误的话就不会处理这个包了
    unsigned payload_unit_start_indicator        :     1;      //有效负载的开始标志，根据后面有效负载的内容不同功能也不同
    unsigned transport_priority                             :     1;      //传输优先级位，1表示高优先级
    unsigned PID                                                     :     13;     //有效负载数据的类型
    unsigned transport_scrambling_control      :     2;      //加密标志位,00表示未加密
    unsigned adaption_field_control                   :     2;      //调整字段控制,。01仅含有效负载，10仅含调整字段，11含有调整字段和有效负载。为00的话解码器不进行处理。
    unsigned continuity_counter                           :    4;    //一个4bit的计数器，范围0-15
} ts_packet_header; 

typedef int (*ts_packet_callback)(unsigned char *pucPacketBuff, unsigned int dwLen);
int mpeg_ts_stream_read(char *pcStreamPath, ts_packet_callback pfTsPacketCallBack);

#endif

