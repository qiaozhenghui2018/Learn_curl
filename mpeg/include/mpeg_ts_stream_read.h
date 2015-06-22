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
    unsigned sync_byte                                         :    8;    //ͬ���ֽڣ��̶�Ϊ0x47 ����ʾ�������һ��TS���飬��Ȼ��������е������ǲ������0x47��
    unsigned transport_error_indicator              :    1;      //��������־λ��һ�㴫�����Ļ��Ͳ��ᴦ���������
    unsigned payload_unit_start_indicator        :     1;      //��Ч���صĿ�ʼ��־�����ݺ�����Ч���ص����ݲ�ͬ����Ҳ��ͬ
    unsigned transport_priority                             :     1;      //�������ȼ�λ��1��ʾ�����ȼ�
    unsigned PID                                                     :     13;     //��Ч�������ݵ�����
    unsigned transport_scrambling_control      :     2;      //���ܱ�־λ,00��ʾδ����
    unsigned adaption_field_control                   :     2;      //�����ֶο���,��01������Ч���أ�10���������ֶΣ�11���е����ֶκ���Ч���ء�Ϊ00�Ļ������������д���
    unsigned continuity_counter                           :    4;    //һ��4bit�ļ���������Χ0-15
} ts_packet_header; 

typedef int (*ts_packet_callback)(unsigned char *pucPacketBuff, unsigned int dwLen);
int mpeg_ts_stream_read(char *pcStreamPath, ts_packet_callback pfTsPacketCallBack);

#endif

