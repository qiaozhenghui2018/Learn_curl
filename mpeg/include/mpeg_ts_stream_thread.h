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

#ifndef _MPEG_TS_STREAM_THREAD_H__
#define _MPEG_TS_STREAM_THREAD_H__

#include <stdio.h>

#define THREAD_TASK_PRIORITY_MIN  1       /* low  */
#define THREAD_TASK_PRIORITY_MAX  99      /* high */

typedef void (*InspurPortingFunc_t)(void);

typedef void (*ThreadFuncType_T)(void);

int mpeg_ts_stream_ThreadCreate(char *name, int priority, int options, int stackSize, ThreadFuncType_T routineEntry, int arg1, int arg2, int arg3, int arg4);
int mpeg_ts_stream_ThreadDelete(int tid);
int mpeg_ts_stream_ThreadDelayMs(int Ms);

#endif

