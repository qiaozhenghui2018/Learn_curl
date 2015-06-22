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
#ifndef __MPEG_TS_STREAM_QUEUE_H__
#define __MPEG_TS_STREAM_QUEUE_H__

#define Millisecond_TO_Seconds (1000)

#define OSAL_MSGQ_WAIT_FOREVER  (0xFFFFFFFF)
#define OSAL_MSGQ_NO_WAIT       (0)

enum Queue_ErrorCode
{
    Queue_success = 0,
    Queue_failure,
    Queue_timeout,
    Queue_parameter_error,
    Queue_other
};

int mpeg_ts_stream_MsgQCreate(int usize, int num, int type);
int mpeg_ts_stream_MsgQDelete(int mid);
int mpeg_ts_stream_MsgQSend(int mid, char *txBuf, int txLen, unsigned int dwTimeOut);
int mpeg_ts_stream_MsgQReceive(int mid, char *rxBuf, int rxLen, unsigned int dwTimeout);
int mpeg_ts_stream_MsgQPrintf(int mid);

#endif

