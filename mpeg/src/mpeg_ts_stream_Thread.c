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

#include <pthread.h>

#include "mpeg_ts_stream_thread.h"

int mpeg_ts_stream_ThreadDelayMs(int Ms)
{
    struct timespec requesttime;
    struct timespec remaintime;
    
    memset(&requesttime, 0, sizeof(requesttime));
    memset(&remaintime, 0, sizeof(remaintime));
    
    requesttime.tv_sec = Ms/1000;
    requesttime.tv_nsec = (Ms%1000)*1000000;

    //usleep may block the thread.
    nanosleep(&requesttime, &remaintime);
    return 0;
}

int mpeg_ts_stream_ThreadCreate(char *name, int priority, int options, int stackSize, ThreadFuncType_T routineEntry, int arg1, int arg2, int arg3, int arg4)
{
    int rc;
    pthread_attr_t  attr;
	
    pthread_t pid;
    
    struct sched_param param;

    if (priority<THREAD_TASK_PRIORITY_MIN || priority>THREAD_TASK_PRIORITY_MAX)
    {
        mpeg_ts_steam_Printf("err@iOsalThreadCreate: bad priority %d\n", priority);
        return 0;
    }
   
    pthread_attr_init(&attr);
    
    rc = pthread_attr_setschedpolicy(&attr, SCHED_FIFO);

    pthread_attr_getschedparam(&attr, &param);
    param.sched_priority = priority;
    pthread_attr_setschedparam(&attr, &param);

    rc = pthread_create (&pid, &attr, (void *(*)(void *))routineEntry, (void *)arg1);
    
    if (rc == 0)
    {
        return pid;
    }
    else
    {
        return 0;
    }
}

int mpeg_ts_stream_ThreadDelete(int tid)
{
    pthread_cancel((pthread_t)tid);
    return -1;
}



