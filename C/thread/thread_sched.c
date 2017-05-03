
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

void
iOsalTimespecPlusMs (struct timespec *pTS, unsigned int millisecond)
{
  struct timeval tv;
  struct timespec ts;
  gettimeofday (&tv, 0);

  ts.tv_sec = tv.tv_sec;
  ts.tv_nsec = tv.tv_usec * 1000;

  ts.tv_sec += (millisecond / 1000);
  ts.tv_nsec += (millisecond % 1000) * 1000000;

  if (ts.tv_nsec >= 1000000000)
    {
      //printf("test: overflow\n");
      ts.tv_nsec -= 1000000000;
      ts.tv_sec += 1;
    }

  *pTS = ts;
}

static void
pthread_delay (int millisecond)
{
  pthread_mutex_t mutex;
  pthread_cond_t cond;
  struct timespec ts;
  //return;

  iOsalTimespecPlusMs (&ts, millisecond);

  pthread_mutex_init (&mutex, 0);
  pthread_cond_init (&cond, 0);

  pthread_mutex_lock (&mutex);
  pthread_cond_timedwait (&cond, &mutex, &ts);
  pthread_mutex_unlock (&mutex);

  pthread_cond_destroy (&cond);
  pthread_mutex_destroy (&mutex);
}

void
Thread1 ()
{
  //sleep(2);
  int i, j;
  int policy;
  struct sched_param param;
  pthread_getschedparam (pthread_self (), &policy, &param);
  if (policy == SCHED_OTHER)
    printf ("SCHED_OTHER 1\n");
  if (policy == SCHED_RR)
    printf ("SCHED_RR 1 \n");
  if (policy == SCHED_FIFO)
    printf ("SCHED_FIFO 1\n");

  printf ("thread 1 param.sched_priority = %d\n", param.sched_priority);
  for (i = 1; i < 10; i++)
    {
      pthread_delay (50);
      printf ("thread 1\n");
    }
  printf ("Pthread 1 exit\n");
}

void
Thread2 ()
{
  //sleep(2);
  int i, j, m;
  int policy;
  struct sched_param param;
  pthread_getschedparam (pthread_self (), &policy, &param);
  if (policy == SCHED_OTHER)
    printf ("SCHED_OTHER 2\n");
  if (policy == SCHED_RR)
    printf ("SCHED_RR 2\n");
  if (policy == SCHED_FIFO)
    printf ("SCHED_FIFO 2\n");

  printf ("thread 2 param.sched_priority = %d\n", param.sched_priority);

  for (i = 1; i < 10; i++)
    {
      pthread_delay (50);
      printf ("thread 2\n");
    }
  printf ("Pthread 2 exit\n");
}

void
Thread3 ()
{
  //sleep(2);
  int i, j;
  int policy;
  struct sched_param param;
  pthread_getschedparam (pthread_self (), &policy, &param);
  if (policy == SCHED_OTHER)
    printf ("SCHED_OTHER 3\n");
  if (policy == SCHED_RR)
    printf ("SCHED_RR 3\n");
  if (policy == SCHED_FIFO)
    printf ("SCHED_FIFO 3\n");

  printf ("thread 3 param.sched_priority = %d\n", param.sched_priority);

  for (i = 1; i < 10; i++)
    {
      pthread_delay (50);
      printf ("thread 3\n");
    }
  printf ("Pthread 3 exit\n");
}

int
main ()
{
  int i;
  i = getuid ();
  if (i == 0)
    printf ("The current user is root\n");
  else
    printf ("The current user is not root\n");

  pthread_t ppid1, ppid2, ppid3;
  struct sched_param param;

  pthread_attr_t attr, attr1, attr2;

  pthread_attr_init (&attr1);
  pthread_attr_init (&attr);
  pthread_attr_init (&attr2);
  param.sched_priority = 51;
  pthread_attr_setschedpolicy (&attr2, SCHED_FIFO);
  pthread_attr_setschedparam (&attr2, &param);
  pthread_attr_setinheritsched (&attr2, PTHREAD_EXPLICIT_SCHED);	//要使优先级其作用必须要有这句话

  param.sched_priority = 21;
  pthread_attr_setschedpolicy (&attr1, SCHED_FIFO);
  pthread_attr_setschedparam (&attr1, &param);
  pthread_attr_setinheritsched (&attr1, PTHREAD_EXPLICIT_SCHED);

  pthread_create (&ppid3, &attr, (void *) Thread3, NULL);
  pthread_create (&ppid2, &attr1, (void *) Thread2, NULL);
  pthread_create (&ppid1, &attr2, (void *) Thread1, NULL);

  pthread_join (ppid3, NULL);
  pthread_join (ppid2, NULL);
  pthread_join (ppid1, NULL);
  pthread_attr_destroy (&attr2);
  pthread_attr_destroy (&attr1);
  return 0;
}
