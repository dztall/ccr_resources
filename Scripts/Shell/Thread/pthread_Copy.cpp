//Original source code found at : http://www.joinc.co.kr/modules/moniwiki/wiki.php/Site/Thread/Beginning/Example_pthread

#if CCR_FORCE_LLVM_INTERPRETER
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

pthread_t threads[5];
int done[5];

void *thread_main(void *);

int main(void)
{
	int i;
	int rc;
	int status;

	printf("pid=%d\n", getpid());

	for (i = 0; i < 5; i++)
	{
		done[i] = 0;
		pthread_create(&threads[i], NULL, &thread_main, (void *)i);
		printf("%d, %d\n", i, *(int *)&threads[i]);
	}

	for (i = 4; i >= 0; i--)
	{
		done[i] = 1;
		rc = pthread_join(threads[i], (void **)&status);
		if (rc == 0)
		{
			printf("Completed join with thread %d status= %d\n", i, status);
		}
		else
		{
			printf("ERROR; return code from pthread_join() is %d, thread %d\n", rc, i);
			return -1;
		}
	}

	return 0;
}

void *thread_main(void *arg)
{
	int i;
	double result = 0.0;

	printf("thread: %d, %d\n", (int)arg, getpid());
	printf("thread: %d while loop\n", (int)arg);
	
	while (!done[(int)arg])
	{
	}
	printf("thread: %d sleeping\n", (int)arg);
sleep(5);
	printf("thread: %d exiting\n", (int)arg);
	pthread_exit((void *)2);
}
