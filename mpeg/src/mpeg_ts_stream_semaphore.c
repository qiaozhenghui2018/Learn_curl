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

#include <semaphore.h>

int mpeg_ts_stream_SemaphoreCreate(int value)
{
    sem_t *sem;
    int rc;

    sem = (sem_t *)calloc(sizeof(sem_t), 1);

    if(!sem)
    {
        return -1;
    }
    
    rc = sem_init(&sem, 0, value);
    return (int)sem;
}

int mpeg_ts_stream_SemaphorePost(int sid)
{
    return sem_post((sem_t*)&sid);
}

int mpeg_ts_stream_SemaphoreWait(int sid)
{
    return sem_wait((sem_t*)&sid);
}

int mpeg_ts_stream_SemaphoreDestory(int sid)
{
    int rc;
    rc = sem_destroy((sem_t*)&sid);
    free((sem_t*)sid);
    return rc;
}

