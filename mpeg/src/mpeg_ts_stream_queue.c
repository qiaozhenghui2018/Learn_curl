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

#include <sys/time.h>

#include "mpeg_ts_stream_queue.h"
#include "mpeg_ts_stream_semaphore.h"
#include "mpeg_ts_stream_log.h"

typedef struct 
{
    int        semRcv;
    int        semSnd;
    int        usize;
    int        size;
    int        wptr;
    int        rptr;
    int        len;

    // debug
    int rxpid, txpid;

    // must be last one
    char       buf;
} msgq_t;

static int getms(void)
{
    int ms;
    struct timeval tv;
    gettimeofday(&tv, 0);

    ms = tv.tv_sec * (int)1000;
    ms += tv.tv_usec / 1000;
    return ms;
}

int mpeg_ts_stream_MsgQCreate(int usize, int num, int type)
{
    msgq_t *pMsgQ;

    pMsgQ = (msgq_t *)calloc(sizeof(msgq_t) + usize * num - 1, 1);

    pMsgQ->usize= usize;
    pMsgQ->size = usize * num;
    pMsgQ->semRcv = mpeg_ts_stream_SemaphoreCreate(0);
    pMsgQ->semSnd = mpeg_ts_stream_SemaphoreCreate(1);
    return (int)pMsgQ;
}

int mpeg_ts_stream_MsgQDelete(int mid)
{
    msgq_t *pMsgQ = (msgq_t *)mid;

    mpeg_ts_stream_SemaphoreDestory(pMsgQ->semRcv);
    mpeg_ts_stream_SemaphoreDestory(pMsgQ->semSnd);
    free(pMsgQ);
    return 0;
}

int mpeg_ts_stream_MsgQSend(int mid, char *txBuf, int txLen, unsigned int dwTimeOut)
{
    msgq_t *pMsgQ = (msgq_t *)mid;
    int     rc, intLevel;
    char   *ptr;
    int ms0, ms1;

    if(!txBuf)
    {
        return Queue_parameter_error;
    }

    ms0 = getms();

retry:
    mpeg_ts_stream_SemaphoreWait(pMsgQ->semSnd);
    if (pMsgQ->len + txLen > pMsgQ->size)
    {
        if (dwTimeOut == OSAL_MSGQ_WAIT_FOREVER)
        {
            mpeg_ts_stream_SemaphorePost(pMsgQ->semSnd);
            mpeg_ts_stream_ThreadDelayMs(1);
            goto retry;
        }
        else if (dwTimeOut == OSAL_MSGQ_NO_WAIT)
        {
            rc = Queue_failure;//error
        }
        else
        {
            ms1 = getms();
            if ((ms1 - ms0) < dwTimeOut)
            {
                mpeg_ts_stream_SemaphorePost(pMsgQ->semSnd);
                mpeg_ts_stream_ThreadDelayMs(1);
                goto retry;
            }
            else
            {
                rc = Queue_timeout;//time out
            }
        }
    }
    else
    {
        pMsgQ->wptr %= pMsgQ->size;
        
        ptr = (char *)&pMsgQ->buf + pMsgQ->wptr;
        
        pMsgQ->len += txLen;

        if (pMsgQ->size - pMsgQ->wptr >= txLen)
        {
            memcpy(ptr, txBuf, txLen);
            pMsgQ->wptr += txLen;
            rc = Queue_success;
        }
        else    //queue is full
        {
            rc = Queue_other;
            mpeg_ts_steam_Printf("------>send queue error\n");
        }
    }

    if (rc == Queue_success)
    {
        mpeg_ts_stream_SemaphorePost(pMsgQ->semRcv);
    }
    
    mpeg_ts_stream_SemaphorePost(pMsgQ->semSnd);

    return rc;
}

int mpeg_ts_stream_MsgQReceive(int mid, char *rxBuf, int rxLen, unsigned int dwTimeout)
{
    int     rc, s, waitMs = 0;
    msgq_t *pMsgQ = (msgq_t *)mid;
    char   *ptr;
    int ms0, ms1;

    if(!rxBuf)
    {
        return Queue_parameter_error;
    }

    ms0 = getms();
    
    if (dwTimeout == OSAL_MSGQ_WAIT_FOREVER)
    {
        mpeg_ts_stream_SemaphoreWait(pMsgQ->semRcv);
    }
    
    pMsgQ->rxpid = getpid();

retry:
    mpeg_ts_stream_SemaphoreWait(pMsgQ->semSnd);

    if (pMsgQ->len < rxLen)
    {
        if (dwTimeout == OSAL_MSGQ_WAIT_FOREVER)
        {
            mpeg_ts_stream_SemaphorePost(pMsgQ->semSnd);
            mpeg_ts_stream_ThreadDelayMs(1);
            goto retry;
        }
        else if (dwTimeout == OSAL_MSGQ_NO_WAIT)
        {
            rc = Queue_timeout;
        }
        else
        {
            ms1 = getms();
            if ((ms1 - ms0) < dwTimeout)
            {
                mpeg_ts_stream_SemaphorePost(pMsgQ->semSnd);
                mpeg_ts_stream_ThreadDelayMs(1);
                goto retry;
            }
            else
            {
                rc = Queue_failure;
            }
        }
    }
    else
    {
        pMsgQ->rptr %= pMsgQ->size;

        s = pMsgQ->size - pMsgQ->rptr;
        
        ptr = (char *)&pMsgQ->buf + pMsgQ->rptr;
        
        pMsgQ->len -= rxLen;
        
        if (s >= rxLen)
        {
            memcpy(rxBuf, ptr, rxLen);
            pMsgQ->rptr += rxLen;

            rc = Queue_success;
        }
        else
        {
            rc = Queue_other;
            mpeg_ts_steam_Printf("------>read queue error\n");
        }
    }

    mpeg_ts_stream_SemaphorePost(pMsgQ->semSnd);
    
    return rc;
}

int mpeg_ts_stream_MsgQPrintf(int mid)
{
    msgq_t *pMsgQ = (msgq_t *)mid;
    int i = 0;

    unsigned char *pucData = &pMsgQ->buf;

    while(i < pMsgQ->size)
    {
        mpeg_ts_steam_Printf(" %02x\n", pucData[i]);
        i++;
    }

    return 0;
}

